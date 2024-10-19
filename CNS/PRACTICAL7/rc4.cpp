#include<iostream>
using namespace std;

string RC_4_Encryption(string key, string plaintext){
    // Creation of initial state and key bytes
    int S[256], K[256];
    for(int i = 0; i < 256; i++){
        S[i] = i;
        K[i] = key[i % key.length()]; 
    }

    // Permuting state bytes based on values of key bytes
    int j = 0;
    for(int i = 0; i < 256; i++){
        j = (j + S[i] + K[i]) % 256;
        swap(S[i], S[j]);
    }

    // Continuously permuting state bytes and generating key stream
    int i = 0, k = 0;
    int plaintext_length = plaintext.length();
    string ciphertext = "";
    for(int itr = 0; itr < plaintext_length; itr++){   
        i = (i + 1) % 256;
        k = (k + S[i]) % 256;
        swap(S[i], S[k]);
        int K = S[(S[i] + S[k]) % 256];

        // XOR with plaintext character to get the ciphertext character
        int p = plaintext[itr];
        int c = p ^ K;

        cout << c << " ";
        // Append encrypted character to the ciphertext
        ciphertext += (char)c;
    }
    return ciphertext;
}

int main()
{
    string key, plaintext;
    cout << "Enter the key: ";
    cin >> key;

    cout << "Enter the plaintext: ";
    cin >> plaintext;

    string res = RC_4_Encryption(key, plaintext);
    cout << "RESULT: " << res << endl;

    string res2 = RC_4_Encryption(key, res);
    cout << "RESULT: " << res2 << endl;
    
    return 0;
}
