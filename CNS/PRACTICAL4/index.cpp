#include <iostream>
#include <bitset>
using namespace std;

void split_word(int n, int word) {
    bitset<16> binary_word(word); // assuming max 16 bits
    string binary_str = binary_word.to_string().substr(16 - n, n); // get n bits
    
    int half = n / 2;
    string left_half = binary_str.substr(0, half);
    string right_half = binary_str.substr(half);
    
    cout << "Left half: " << left_half << ", Right half: " << right_half << endl;
}

int main() {
    int n = 8; // 8-bit word
    int word = 0b11001010;
    split_word(n, word);
    return 0;
}
