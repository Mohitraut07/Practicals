#include <iostream>
#include <map>
#define itr std::map<int, char>::iterator
using namespace std;

// Implement Caesar Cipher Method of Encryption
// Implement Additive Caesar Cipher Method
string encryption(string ipt, map<int, char> upperCase, map<int, char> lowerCase, int k = 3)
{
    string result;
    int ipt_key;
    for (char c : ipt)
    {
        if (islower(c))
        {
            for (itr it = lowerCase.begin(); it != lowerCase.end(); it++)
            {
                if (it->second == c)
                {
                    ipt_key = it->first;
                    // cout << ipt_key << endl;
                    break;
                }
            }
            int index = (ipt_key + k) % 26;
            result += upperCase[index];
        }
        else
            return "Error: Enter Valid input string!!!";
    }
    return result;
}

string decryption(string ipt, map<int, char> lowerCase, map<int, char> upperCase, int k = 3)
{
    string result;
    int ipt_key;
    for (char c : ipt)
    {
        if (isupper(c))
        {
            for (itr it = upperCase.begin(); it != upperCase.end(); it++)
            {
                if (it->second == c)
                {
                    ipt_key = it->first;
                    break;
                }
            }
            int index = (ipt_key - k);
            if (index < 0)
                index += 26;
            result += lowerCase[index];
        }
        else
            return "Error: Enter Valid input string!!!";
    }
    return result;
}


// Driver Code
int main()
{
    map<int, char> lowerCase;
    for (int i = 0; i < 26; ++i)
    {
        lowerCase[i] = 'a' + i;
    }

    map<int, char> upperCase;
    for (int i = 0; i < 26; ++i)
    {
        upperCase[i] = 'A' + i;
    }

    string result, input;

    int choice;
    cout << "Enter 1 for Caesar Cipher and 2 for Additive Caesar Cipher" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        int choice1;
        cout << "Welcome!" << endl
             << "Please enter your choice:" << endl
             << "1 for ENCRYPTION" << endl
             << "2 for DECRYPTION" << endl;
        cin >> choice1;
        cout << "Enter the input string : " << endl;
        cin.ignore(); // To ignore the newline character left in the input buffer
        getline(cin, input);
        switch (choice1)
        {
        case 1:
            result = encryption(input, upperCase, lowerCase);
            break;
        case 2:
            result = decryption(input, lowerCase, upperCase);
            break;

        default:
            cout << "Enter valid input" << endl;
            break;
        }

        break;
    case 2:
        int choice2, k;
        cout << "Welcome!" << endl
             << "Please enter your choice:" << endl
             << "1 for ENCRYPTION" << endl
             << "2 for DECRYPTION" << endl;
        cin >> choice2;
        cout << "Enter the input string : " << endl;
        cin.ignore(); // To ignore the newline character left in the input buffer
        getline(cin, input);
        cout << "Enter the value of 'k': " << endl;
        cin >> k;
        switch (choice2)
        {
        case 1:
            result = encryption(input, upperCase, lowerCase, k);
            break;
        case 2:
            result = decryption(input, lowerCase, upperCase, k);
            break;

        default:
            cout << "Enter valid input" << endl;
            break;
        }

        break;

    default:
        cout << "Enter valid input" << endl;
        break;
    }

    cout << "The result string is: " << result << endl;

    return 0;
}