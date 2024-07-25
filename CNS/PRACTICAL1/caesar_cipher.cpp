#include <iostream>
#include <map>
#define k 3
#define itr std::map <int, char>::iterator
using namespace std;


// Implement Caesar Cipher Method of Encryption
string encryption(string ipt,map < int, char > &upperCase, map < int, char > &lowerCase) {
    string result;
    int ipt_key ;
    for (char c : ipt) {
        for(itr it = lowerCase.begin(); it != lowerCase.end(); it++){
            if(it->second == c){
                ipt_key = it->first;
                // cout << ipt_key << endl;
                break;
            }
        }
        int index = (ipt_key + k) % 26;
        result += upperCase[index];
    }
    return result;
}

string decryption(string ipt,map  < int, char > &lowerCase, map < int, char > &upperCase) {
    string result;
    int ipt_key;
    for (char c : ipt) {
        for(itr it = upperCase.begin(); it != upperCase.end(); it++){
            if(it->second == c){
                ipt_key = it->first;
                break;
            }
        }
        int index = (ipt_key - k);
        if (index < 0) index += 26;
        result += lowerCase[index];
    }
    return result;
}

int main()
{
    map<int, char> lowerCase;
    for (int i = 0; i < 26; ++i) {
        lowerCase[i] = 'a' + i;
    }

    map<int, char> upperCase;
    for (int i = 0; i < 26; ++i) {
        upperCase[i] = 'A' + i;
    }

    int choice;
    string result, input;
    cout << "Welcome!" << endl
         << "Please enter your choice:" << endl
         << "1 for ENCRYPTION" << endl
         << "2 for DECRYPTION" << endl;
    cin >> choice;
    cout << "Enter the input string : "<< endl;
    cin.ignore(); // To ignore the newline character left in the input buffer
    getline(cin, input);
    switch (choice)
    {
    case 1:
        result = encryption(input,upperCase,lowerCase);
        break;
    case 2:
        result = decryption(input,lowerCase,upperCase);
        break;

    default:
        cout << "Enter valid input" << endl;
        break;
    }

    cout << "The result string is: " << result << endl;

    return 0;
}