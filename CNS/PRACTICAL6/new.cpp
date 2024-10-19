#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

// S-box for SubBytes transformation
const string S[16][16] = {
    {"63", "7c", "77", "7b", "f2", "6b", "6f", "c5", "30", "01", "67", "2b", "fe", "d7", "ab", "76"},
    {"ca", "82", "c9", "7d", "fa", "59", "47", "f0", "ad", "d4", "a2", "af", "9c", "a4", "72", "c0"},
    {"b7", "fd", "93", "26", "36", "3f", "f7", "cc", "34", "a5", "e5", "f1", "71", "d8", "31", "15"},
    {"04", "c7", "23", "c3", "18", "96", "05", "9a", "07", "12", "80", "e2", "eb", "27", "b2", "75"},
    {"09", "83", "2c", "1a", "1b", "6e", "5a", "a0", "52", "3b", "d6", "b3", "29", "e3", "2f", "84"},
    {"53", "d1", "00", "ed", "20", "fc", "b1", "5b", "6a", "cb", "be", "39", "4a", "4c", "58", "cf"},
    {"d0", "ef", "aa", "fb", "43", "4d", "33", "85", "45", "f9", "02", "7f", "50", "3c", "9f", "a8"},
    {"51", "a3", "40", "8f", "92", "9d", "38", "f5", "bc", "b6", "da", "21", "10", "ff", "f3", "d2"},
    {"cd", "0c", "13", "ec", "5f", "97", "44", "17", "c4", "a7", "7e", "3d", "64", "5d", "19", "73"},
    {"60", "81", "4f", "dc", "22", "2a", "90", "88", "46", "ee", "b8", "14", "de", "5e", "0b", "db"},
    {"e0", "32", "3a", "0a", "49", "06", "24", "5c", "c2", "d3", "ac", "62", "91", "95", "e4", "79"},
    {"e7", "c8", "37", "6d", "8d", "d5", "4e", "a9", "6c", "56", "f4", "ea", "65", "7a", "ae", "08"},
    {"ba", "78", "25", "2e", "1c", "a6", "b4", "c6", "e8", "dd", "74", "1f", "4b", "bd", "8b", "8a"},
    {"70", "3e", "b5", "66", "48", "03", "f6", "0e", "61", "35", "57", "b9", "86", "c1", "1d", "9e"},
    {"e1", "f8", "98", "11", "69", "d9", "8e", "94", "9b", "1e", "87", "e9", "ce", "55", "28", "df"},
    {"8c", "a1", "89", "0d", "bf", "e6", "42", "68", "41", "99", "2d", "0f", "b0", "54", "bb", "16"}
};

// Round constants
const string Rconst[11] = {
    "00000000", "01000000", "02000000", "04000000", "08000000",
    "10000000", "20000000", "40000000", "80000000", "1B000000", "36000000"
};

// Function to perform XOR operation
vector<string> xorOperation(const vector<string>& a, const vector<string>& b) {
    vector<string> result;
    for (size_t i = 0; i < a.size(); i++) {
        string res = "";
        for (int j = 0; j < a[i].length(); j += 2) {
            int x = stoi(a[i].substr(j, 2), nullptr, 16);
            int y = stoi(b[i].substr(j, 2), nullptr, 16);
            res += to_string((x ^ y) & 0xFF);
        }
        result.push_back(res);
    }
    return result;
}

string xorOperation(string a, string b) {
    string result = "";
    for (int i = 0; i < a.length(); i++) {
        result += to_string((stoi(a.substr(i, 2), 0, 16) ^ stoi(b.substr(i, 2), 0, 16)) & 0xFF);
    }
    return result;
}

// Function to perform SubBytes transformation
vector<string> subBytes(vector<string> state) {
    vector<string> newState;
    for (string word : state) {
        string newWord = "";
        for (int i = 0; i < 8; i += 2) {
            int x = stoi(word.substr(i, 1), 0, 16);
            int y = stoi(word.substr(i + 1, 1), 0, 16);
            newWord += S[x][y];
        }
        newState.push_back(newWord);
    }
    return newState;
}

// Function to perform ShiftRows transformation
vector<string> shiftRows(vector<string> state) {
    string text = "";
    for (string word : state) {
        text += word;
    }

    string w1 = text.substr(0, 2) + text.substr(10, 2) + text.substr(20, 2) + text.substr(30, 2);
    string w2 = text.substr(8, 2) + text.substr(18, 2) + text.substr(28, 2) + text.substr(6, 2);
    string w3 = text.substr(16, 2) + text.substr(26, 2) + text.substr(4, 2) + text.substr(14, 2);
    string w4 = text.substr(24, 2) + text.substr(2, 2) + text.substr(12, 2) + text.substr(22, 2);

    return {w1, w2, w3, w4};
}

// Function to perform MixColumns transformation
vector<string> mixColumns(vector<string> state) {
    vector<string> newState;
    for (string word : state) {
        int a = stoi(word.substr(0, 2), 0, 16);
        int b = stoi(word.substr(2, 2), 0, 16);
        int c = stoi(word.substr(4, 2), 0, 16);
        int d = stoi(word.substr(6, 2), 0, 16);

        string w1 = to_string(((a << 1) ^ ((a >> 7) & 1) ^ ((a >> 5) & 1) ^ ((a >> 4) & 1) ^ ((a >> 3) & 1) ^ ((a >> 2) & 1) ^ ((a >> 1) & 1)) & 0xFF);
        string w2 = to_string(((b << 1) ^ ((b >> 7) & 1) ^ ((b >> 5) & 1) ^ ((b >> 4) & 1) ^ ((b >> 3) & 1) ^ ((b >> 2) & 1) ^ (( b >> 1) & 1)) & 0xFF);
        string w3 = to_string(((c << 1) ^ ((c >> 7) & 1) ^ ((c >> 5) & 1) ^ ((c >> 4) & 1) ^ ((c >> 3) & 1) ^ ((c >> 2) & 1) ^ ((c >> 1) & 1)) & 0xFF);
        string w4 = to_string(((d << 1) ^ ((d >> 7) & 1) ^ ((d >> 5) & 1) ^ ((d >> 4) & 1) ^ ((d >> 3) & 1) ^ ((d >> 2) & 1) ^ ((d >> 1) & 1)) & 0xFF);

        newState.push_back(w1 + w2 + w3 + w4);
    }
    return newState;
}

// Function to generate round keys
vector<string> generateRoundKeys(vector<string> keywords, int roundCount) {
    string Rcnst = Rconst[roundCount];
    string four = keywords[3];
    four = four.substr(2) + four.substr(0, 2); // Rotate Word
    four = subBytes({four})[0]; // SubWord
    four = xorOperation(four, Rcnst); // XOR with Rconst

    vector<string> newKeywords;
    newKeywords.push_back(four);
    for (int i = 0; i < 3; i++) {
        newKeywords.push_back(xorOperation(newKeywords[i], keywords[i]));
    }
    return newKeywords;
}

// Function to perform AES encryption
vector<string> aesEncryption(vector<string> plaintext, vector<string> keywords) {
    vector<string> stateMatrix = plaintext;
    for (int roundCount = 0; roundCount < 10; roundCount++) {
        stateMatrix = subBytes(stateMatrix);
        stateMatrix = shiftRows(stateMatrix);
        if (roundCount != 9) {
            stateMatrix = mixColumns(stateMatrix);
        }
        keywords = generateRoundKeys(keywords, roundCount + 1);
        stateMatrix = xorOperation(stateMatrix, keywords); // Corrected line
    }
    return stateMatrix;
}

int main() {
    vector<string> plaintext;
    cout << "Enter plaintext (in HEX format XXXX XXXX XXXX XXXX): ";
    string input;
    getline(cin, input);
    istringstream iss(input);
    string token;
    while (getline(iss, token, ' ')) {
        plaintext.push_back(token);
    }

    vector<string> keywords;
    cout << "Enter keywords (in HEX format XXXX XXXX XXXX XXXX): ";
    getline(cin, input);
    iss.str(input);
    while (getline(iss, token, ' ')) {
        keywords.push_back(token);
    }

    if (plaintext.size() != 4 || keywords.size() != 4) {
        cout << "There must be 4 input keys" << endl;
        return 1;
    }

    for (string key : keywords) {
        if (key.length() != 8) {
            cout << "Each input key must be 8 hex characters long!" << endl;
            return 1;
        }
    }

    vector<string> encryptedText = aesEncryption(plaintext, keywords);
    cout << "Encrypted text: ";
    for (string word : encryptedText) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}