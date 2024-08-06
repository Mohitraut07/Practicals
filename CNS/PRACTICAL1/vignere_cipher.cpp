#include <iostream>
using namespace std;

string encryption(string input, char *key_str, int size)
{
    string result;
    for (int i = 0; i < size; i++)
    {
        result += 'A' + (((int(key_str[i]) - 65) + (int(input[i]) - 97)) % 26);
        // cout << int(key_str[i]-65) << " " << int(input[i]-97) << endl;
        // cout << result[i] << endl;
    }
    return result;
}
string decryption(string input, char *key_str, int size)
{
    string result;
    for (int i = 0; i < size; i++)
    {
        int dec_char = ((int(input[i])-'A')-(int(key_str[i])-'A') % 26);
        if(dec_char <0) dec_char += 26;
        result += 'a' + dec_char;
    }
    return result;
}

int main()
{
    string result, key, input;
    int choice, size;
    cout << "Welcome!!!" << endl
         << "Please enter your choice:" << endl
         << "1 for ENCRYPTION" << endl
         << "2 for DECRYPTION" << endl;
    cin >> choice;
    cout << "Enter the input string : " << endl;
    cin.ignore(); // To ignore the newline character left in the input buffer
    getline(cin, input);

    cout << "Enter the required key : " << endl;
    getline(cin, key);

    size = input.size();
    char key_str[size];

    for (int i = 0; i < size; i++)
    {
        key_str[i] = key[i % key.size()];
    }

    // for(char c:key_str){
    //     cout << c << endl;
    // }

    switch (choice)
    {
    case 1:
        result = encryption(input, key_str, size);
        break;
    case 2:
        result = decryption(input, key_str, size);
        break;

    default:
        cout << "Enter valid input" << endl;
        break;
    }

    cout << "The result string is: " << result << endl;
    return 0;
}