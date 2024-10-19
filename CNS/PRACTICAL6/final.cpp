#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdint>
#include <vector>

using namespace std;

// Standard AES S-box
const uint8_t sbox[256] = { /*... Fill this with the actual S-box values ...*/ };

// AES Rcon
const uint32_t Rcon[10] = {
    0x01000000, 0x02000000, 0x04000000, 0x08000000,
    0x10000000, 0x20000000, 0x40000000, 0x80000000,
    0x1b000000, 0x36000000
};

// A 4x4 matrix representing the state
typedef uint8_t state_t[4][4];

// Function to convert hex string to byte
int hexToByte(const string& hexStr) {
    int byte;
    stringstream ss;
    ss << hex << hexStr;
    ss >> byte;
    return byte;
}

void inputState(state_t& state) {
    cout << "Enter the state matrix (4x4) in hexadecimal format (16 values):" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            string hexStr;
            cin >> hexStr;
            state[i][j] = static_cast<uint8_t>(hexToByte(hexStr));
        }
    }
}

void SubBytes(state_t& state) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] = sbox[state[i][j]];
        }
    }
}

void ShiftRows(state_t& state) {
    uint8_t temp;

    // Rotate first row 1 columns to left
    temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    // Rotate second row 2 columns to left
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;

    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    // Rotate third row 3 columns to left
    temp = state[3][0];
    state[3][0] = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = temp;
}

uint8_t xtime(uint8_t x) {
    return (x << 1) ^ (((x >> 7) & 1) * 0x1b);
}

void MixColumns(state_t& state) {
    for (int i = 0; i < 4; i++) {
        uint8_t t = state[0][i] ^ state[1][i] ^ state[2][i] ^ state[3][i];
        uint8_t temp0 = state[0][i];
        state[0][i] ^= xtime(state[0][i] ^ state[1][i]) ^ t;
        state[1][i] ^= xtime(state[1][i] ^ state[2][i]) ^ t;
        state[2][i] ^= xtime(state[2][i] ^ state[3][i]) ^ t;
        state[3][i] ^= xtime(state[3][i] ^ temp0) ^ t;
    }
}

void AddRoundKey(state_t& state, const uint8_t* roundKey) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            state[i][j] ^= roundKey[i * 4 + j];
        }
    }
}

void PrintState(const state_t& state) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << hex << setw(2) << setfill('0') << (int)state[i][j] << " ";
        }
        cout << endl;
    }
}

// Key expansion functions
uint32_t RotWord(uint32_t word) {
    return (word << 8) | (word >> 24);
}

uint32_t SubWord(uint32_t word) {
    return (sbox[word >> 24] << 24) | (sbox[(word >> 16) & 0xff] << 16) |
           (sbox[(word >> 8) & 0xff] << 8) | (sbox[word & 0xff]);
}

vector<uint32_t> KeyExpansion(const uint8_t* inputKey) {
    vector<uint32_t> expandedKeys(44); // 44 words for AES-128

    for (int i = 0; i < 4; ++i) {
        expandedKeys[i] = (inputKey[i * 4] << 24) |
                          (inputKey[i * 4 + 1] << 16) |
                          (inputKey[i * 4 + 2] << 8) |
                          inputKey[i * 4 + 3];
    }

    for (int i = 4; i < 44; ++i) {
        uint32_t tmp = expandedKeys[i - 1];
        if (i % 4 == 0) {
            tmp = SubWord(RotWord(tmp)) ^ Rcon[i / 4 - 1]; // Rcon is applied only on multiples of 4
        }
        expandedKeys[i] = expandedKeys[i - 4] ^ tmp;
    }

    return expandedKeys;
}

int main() {
    state_t state;
    uint8_t key[16];

    inputState(state);
    cout << "Enter 128-bit key (16 bytes in hexadecimal):" << endl;
    for (int i = 0; i < 16; i++) {
        string hexStr;
        cin >> hexStr;
        key[i] = static_cast<uint8_t>(hexToByte(hexStr));
    }

    // Generate round keys using key expansion
    vector<uint32_t> roundKeys = KeyExpansion(key);

    // Pre-round transformation
    cout << "Initial state:" << endl;
    PrintState(state);
    cout << endl;

    // Use the first 16 bytes of the expanded key for pre-round transformation
    AddRoundKey(state, (uint8_t*)&roundKeys[0]);
    cout << "After Pre-Round Transformation:" << endl;
    PrintState(state);

    // Perform 10 rounds
    for (int round = 1; round <= 10; ++round) {
        cout << "Round " << round << ":" << endl;

        // SubBytes
        SubBytes(state);
        cout << "After SubBytes:" << endl;
        PrintState(state);

        // ShiftRows
        ShiftRows(state);
        cout << "After ShiftRows:" << endl;
        PrintState(state);

        // MixColumns (skip in final round)
        if (round < 10) {
            MixColumns(state);
            cout << "After MixColumns:" << endl;
            PrintState(state);
        }

        // AddRoundKey
        AddRoundKey(state, (uint8_t*)&roundKeys[round * 4]);
        cout << "After AddRoundKey:" << endl;
        PrintState(state);
    }

    // Final state after all rounds
    cout << "Final output state:" << endl;
    PrintState(state);

    return 0;
}
