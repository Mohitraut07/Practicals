#include <iostream>
#include <string>
#define MAX 100
using namespace std;

string removeSpace(string plainText)
{
    string plainTextWithoutSpace = "";
    for (char c : plainText)
    {
        if (c != ' ')
        {
            plainTextWithoutSpace += c;
        }
    }
    return plainTextWithoutSpace;
}

string Encryption(int key[], int length, string plainText)
{
    int maxCol = key[0];

    for (int i = 0; i < length; i++)
    {
        maxCol = max(key[i], maxCol);
    }

    int maxRow = (plainText.size() + maxCol - 1) / maxCol;
    char array[maxRow][maxCol];
    int k = 0;

    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            if (k < plainText.size())
            {
                array[i][j] = plainText[k];
                k++;
            }
            else
            {
                array[i][j] = 'X';  // Padding with 'X' to handle incomplete rows
            }
        }
    }

    cout << "Array structure (Encrypt): \n";
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    string cipherText = "";
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < maxRow; j++)
        {
            cipherText += toupper(array[j][key[i] - 1]);
        }
    }
    return cipherText;
}

string Decryption(int key[], int length, string cipherText)
{
    int maxCol = key[0];

    for (int i = 0; i < length; i++)
    {
        maxCol = max(key[i], maxCol);
    }

    int maxRow = (cipherText.size() + maxCol - 1) / maxCol;
    char array[maxRow][maxCol];
    int k = 0;

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < maxRow; j++)
        {
            array[j][key[i] - 1] = tolower(cipherText[k]);
            k++;
        }
    }

    string plainText = "";
    cout << "Array structure (Decrypt): \n";
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            cout << array[i][j] << " ";
            if (array[i][j] != 'X')  // Ignore padding characters
            {
                plainText += array[i][j];
            }
        }
        cout << endl;
    }

    return plainText;
}

int main()
{
    string plainText;
    string modifyPlainText;
    int key[MAX];
    int length = 0;

    cout << "Enter the plainText (lower case) : ";
    getline(cin, plainText);

    modifyPlainText = removeSpace(plainText);

    cout << "Enter the key (-1 to stop): ";
    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
        {
            break;
        }
        key[length] = n;
        length++;
    }

    string cipherText = Encryption(key, length, modifyPlainText);
    cout << "Cipher Text: " << cipherText << endl;

    string decryptPlainText = Decryption(key, length, cipherText);
    cout << "Decrypted Text: " << decryptPlainText << endl;

    return 0;
}