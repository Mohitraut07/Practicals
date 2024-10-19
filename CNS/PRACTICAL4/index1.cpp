#include <iostream>
#include <bitset>
using namespace std;

int swap_halves(int n, int word) {
    bitset<16> binary_word(word); // assuming max 16 bits
    string binary_str = binary_word.to_string().substr(16 - n, n); // get n bits
    
    int half = n / 2;
    string left_half = binary_str.substr(0, half);
    string right_half = binary_str.substr(half);
    
    string swapped_word = right_half + left_half;
    bitset<16> result(swapped_word);
    
    return (int)result.to_ulong();
}

int main() {
    int n = 8;
    int word = 0b11001010;
    int swapped_word = swap_halves(n, word);
    cout << "Swapped word: " << bitset<8>(swapped_word) << endl;
    return 0;
}
