#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to calculate the determinant of a 2x2 matrix
int determinant(int keyMatrix[2][2]) {
    return (keyMatrix[0][0] * keyMatrix[1][1]) - (keyMatrix[0][1] * keyMatrix[1][0]);
}

// Function to find the multiplicative inverse of a number modulo 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse doesn't exist
}

// Function to find the inverse of a 2x2 key matrix modulo 26
void inverseKeyMatrix(int keyMatrix[2][2], int invKeyMatrix[2][2]) {
    int det = determinant(keyMatrix);
    int invDet = modInverse(det, 26);

    if (invDet == -1) {
        cout << "Inverse of the matrix doesn't exist. Encryption not possible.\n";
        exit(1);
    }

    invKeyMatrix[0][0] = ( keyMatrix[1][1] * invDet) % 26;
    invKeyMatrix[0][1] = (-keyMatrix[0][1] * invDet) % 26;
    invKeyMatrix[1][0] = (-keyMatrix[1][0] * invDet) % 26;
    invKeyMatrix[1][1] = ( keyMatrix[0][0] * invDet) % 26;

    // Handle negative values to ensure they are within the modulo range
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (invKeyMatrix[i][j] < 0) {
                invKeyMatrix[i][j] += 26;
            }
        }
    }
}

// Function to encrypt a pair of characters using the Hill Cipher key
string encryptPair(int keyMatrix[2][2], string pair) {
    string result = "";
    int p1 = pair[0] - 'A';
    int p2 = pair[1] - 'A';

    int c1 = (keyMatrix[0][0] * p1 + keyMatrix[0][1] * p2) % 26;
    int c2 = (keyMatrix[1][0] * p1 + keyMatrix[1][1] * p2) % 26;

    result += (c1 + 'A');
    result += (c2 + 'A');

    return result;
}

// Function to decrypt a pair of characters using the inverse of the Hill Cipher key
string decryptPair(int invKeyMatrix[2][2], string pair) {
    string result = "";
    int c1 = pair[0] - 'A';
    int c2 = pair[1] - 'A';

    int p1 = (invKeyMatrix[0][0] * c1 + invKeyMatrix[0][1] * c2) % 26;
    int p2 = (invKeyMatrix[1][0] * c1 + invKeyMatrix[1][1] * c2) % 26;

    result += (p1 + 'A');
    result += (p2 + 'A');

    return result;
}

int main() {
    string data;
    int keyMatrix[2][2] = {{3, 3}, {2, 5}};
    int invKeyMatrix[2][2];

    cout << "Enter the data to encrypt (must be in uppercase and even length): ";
    cin >> data;

    // If data length is odd, append 'X' to make it even
    if (data.length() % 2 != 0) {
        data += 'X';
    }

    // Encrypt the data
    string encryptedData = "";
    for (size_t i = 0; i < data.length(); i += 2) {
        encryptedData += encryptPair(keyMatrix, data.substr(i, 2));
    }

    cout << "Encrypted Data: " << encryptedData << endl;

    // Calculate inverse key matrix
    inverseKeyMatrix(keyMatrix, invKeyMatrix);

    // Decrypt the data
    string decryptedData = "";
    for (size_t i = 0; i < encryptedData.length(); i += 2) {
        decryptedData += decryptPair(invKeyMatrix, encryptedData.substr(i, 2));
    }

    cout << "Decrypted Data: " << decryptedData << endl;

    return 0;
}
