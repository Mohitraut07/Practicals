#include <iostream>
#include <string>
using namespace std;

string p_box_mapping(string input_bits, int p_box[], int n) {
    string output_bits = "";
    for (int i = 0; i < n; i++) {
        output_bits += input_bits[p_box[i] - 1];
    }
    return output_bits;
}

int main() {
    string input_bits = "11001010";
    int p_box[8] = {2, 4, 6, 8, 1, 3, 5, 7}; // Example P-box
    string output_bits = p_box_mapping(input_bits, p_box, 8);
    
    cout << "Output after P-box mapping: " << output_bits << endl;
    return 0;
}
