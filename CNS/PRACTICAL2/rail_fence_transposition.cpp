#include <iostream>
using namespace std;

string encryption(string input, int key)
{
    char rail[key][input.size()];
    string result;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < input.size(); j++)
        {
            rail[i][j] = '_';
        }
    }

    bool dir = false;
    int row = 0, col = 0;

    for (int j = 0; j < input.size(); j++)
    {
        if (row == 0 || row == key - 1)
        {
            dir = !dir;
        }
        rail[row][col++] = input[j];

        dir ? row++ : row--;
    }

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < input.size(); j++)
        {
            if (rail[i][j] != '_')
            {
                result.push_back(rail[i][j]);
            }
        }
    }

    return result;
}

string decryption(string cipher_text, int key)
{
    char rail[key][cipher_text.size()];
    string result;

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < cipher_text.size(); j++)
        {
            rail[i][j] = '_';
        }
    }

    int row = 0, col = 0;
    bool dir = false;

    for (int j = 0; j < cipher_text.size(); j++)
    {
        rail[row][col++] = '*';
        if (row == 0 || row == key - 1)
        {
            dir = !dir;
        }
        dir ? row++ : row--;
    }

    int index = 0;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < cipher_text.size(); j++)
        {
            if (rail[i][j] == '*' && index < cipher_text.size())
            {
                rail[i][j] = cipher_text[index++];
            }
        }
    }

    row = 0;
    col = 0;
    dir = false;

    for (int j = 0; j < cipher_text.size(); j++)
    {
        result.push_back(rail[row][col++]);
        if (row == 0 || row == key - 1)
        {
            dir = !dir;
        }
        dir ? row++ : row--;
    }

    return result;
}


int main()
{
    int choice1, key;
    string input, result;
    cout << "Welcome!!!" << endl
         << "Please enter your choice:" << endl
         << "1 for ENCRYPTION" << endl
         << "2 for DECRYPTION" << endl;
    cin >> choice1;
    cout << "Enter the input string : " << endl;
    cin.ignore(); // To ignore the newline character left in the input buffer
    getline(cin, input);

    cout << "Enter your key value: ";
    cin >> key;

    switch (choice1)
    {
    case 1:
        result = encryption(input, key);
        break;
    case 2:
        result = decryption(input, key);
        break;

    default:
        cout << "Enter valid input" << endl;
        break;
    }

    cout << "The result is: " << result;
    return 0;
}