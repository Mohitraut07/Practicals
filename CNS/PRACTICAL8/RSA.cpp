#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstdlib> // for rand()

using namespace std;

set<int> prime; // a set will be the collection of prime numbers
int public_key;
int private_key;
int n;

// Function to fill the set of prime numbers using the sieve of Eratosthenes
void primefiller() {
    vector<bool> sieve(250, true);
    sieve[0] = false;
    sieve[1] = false;
    for (int i = 2; i < 250; i++) {
        for (int j = i * 2; j < 250; j += i) {
            sieve[j] = false;
        }
    }
    // Filling the prime numbers
    for (int i = 0; i < sieve.size(); i++) {
        if (sieve[i])
            prime.insert(i);
    }
}

// Function to pick a random prime number and erasing that prime from the list
int pickrandomprime() {
    int k = rand() % prime.size();
    auto it = prime.begin();
    while (k--)
        it++;
    int ret = *it;
    prime.erase(it);
    return ret;
}

// Function to set the public and private keys
void setkeys() {
    int prime1 = pickrandomprime(); // first prime number
    int prime2 = pickrandomprime(); // second prime number
    n = prime1 * prime2;
    unsigned int fi = (prime1 - 1) * (prime2 - 1); // φ(n)
    unsigned int e = 2;

    // Finding public key e
    while (true) {
        if (gcd(e, fi) == 1)
            break;
        e++;
    }
    public_key = e;

    // Finding private key d
    unsigned int d = 2;
    while (true) {
        if ((d * e) % fi == 1)
            break;
        d++;
    }
    private_key = d;
}

// Function to encrypt the given number
long long int encrypt(int message) {
    unsigned int e = public_key;
    long long int encrypted_text = 1;
    while (e--) {
        encrypted_text *= message;
        encrypted_text %= n;
    }
    return encrypted_text;
}

// Function to decrypt the given number
long long int decrypt(int encrypted_text) {
    unsigned int d = private_key;
    long long int decrypted = 1;
    while (d--) {
        decrypted *= encrypted_text;
        decrypted %= n;
    }
    return decrypted;
}

// Function to encode the message (convert each character to its ASCII value, then encrypt)
vector<int> encoder(const string& message) {
    vector<int> form;
    for (auto& letter : message)
        form.push_back(encrypt(static_cast<int>(letter))); // Cast char to int for ASCII value
    return form;
}

// Function to decode the encrypted message (decrypt the encoded ASCII, then convert back to char)
string decoder(const vector<int>& encoded) {
    string s;
    for (auto& num : encoded)
        s += static_cast<char>(decrypt(num)); // Cast int back to char
    return s;
}

int main() {
    primefiller();
    setkeys();

    // Input message from the user
    string message;
    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    // Encoding (encryption using public key)
    vector<int> coded = encoder(message);

    // Display original and encoded messages
    cout << "\nInitial message:\n" << message;
    cout << "\nThe encoded message (encrypted by public key):\n";
    for (auto& p : coded)
        cout << p << " ";
    
    // Decoding (decryption using private key)
    cout << "\n\nThe decoded message (decrypted by private key):\n";
    cout << decoder(coded) << endl;

    return 0;
}
