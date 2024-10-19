#include <iostream>
#include <bitset>
using namespace std;

pair<string, string> split_word(int n, int word) {
    bitset<16> binary_word(word); // assuming max 16 bits
    string binary_str = binary_word.to_string().substr(16 - n, n); // get n bits
    
    int half = n / 2;
    string left_half = binary_str.substr(0, half);
    string right_half = binary_str.substr(half);
    
    return {left_half, right_half};
}

pair<string, string> feistel_round(string left, string right, int subkey) {
    bitset<8> left_bits(left);
    int left_value = (int)left_bits.to_ulong();
    bitset<8> new_right(left_value ^ subkey);  // XOR with subkey
    return {right, new_right.to_string().substr(8 - left.size())};
}

string feistel_cipher(int word, int subkeys[], int n) {
    auto halves = split_word(16, word);
    string left = halves.first;
    string right = halves.second;
    
    for (int i = 0; i < n; i++) {
        auto result = feistel_round(left, right, subkeys[i]);
        left = result.first;
        right = result.second;
    }
    
    return left + right;
}

int main() {
    int word = 0b1100101010110010;  // 16-bit word
    int subkeys[2] = {0b1010, 0b1100};  // Subkeys for two rounds
    string encrypted_word = feistel_cipher(word, subkeys, 2);
    
    cout << "Encrypted word: " << encrypted_word << endl;
    return 0;
}
