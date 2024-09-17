#include <iostream>
using namespace std;

void createInverseKey(int encryptionKey[], int length, int inverseKey[])
{

    for (int i = 0; i < length; i++)
    {

        inverseKey[encryptionKey[i] - 1] = i + 1;
    }
}

int main()
{
    int length;

    cout << "Enter the length of the key: ";
    cin >> length;

    int encryptionKey[length];
    int inverseKey[length];

    cout << "Enter the encryption key values: ";
    for (int i = 0; i < length; i++)
    {
        cin >> encryptionKey[i];
    }

    createInverseKey(encryptionKey, length, inverseKey);

    cout << "The inverse (decryption) key is: ";
    for (int i = 0; i < length; i++)
    {
        cout << inverseKey[i] << " ";
    }
    cout << endl;

    return 0;
}