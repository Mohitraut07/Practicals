#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 30

void toLowerCase(char str[], int size) {
    for (int i = 0; i < size; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 'a' - 'A';
    }
}

int removeSpaces(char str[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (str[i] != ' ')
            str[count++] = str[i];
    }
    str[count] = '\0';
    return count;
}

void generateKeyTable(char key[], int ks, char keyT[5][5]) {
    int dicty[26] = {0};

    for (int i = 0; i < ks; i++) {
        if (key[i] != 'j')
            dicty[key[i] - 'a'] = 2;
    }
    dicty['j' - 'a'] = 1;

    int i = 0, j = 0;
    for (int k = 0; k < ks; k++) {
        if (dicty[key[k] - 'a'] == 2) {
            dicty[key[k] - 'a'] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }

    for (int k = 0; k < 26; k++) {
        if (dicty[k] == 0) {
            keyT[i][j] = 'a' + k;
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
}

void search(char keyT[5][5], char a, char b, int arr[]) {
    if (a == 'j') a = 'i';
    if (b == 'j') b = 'i';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            if (keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int mod5(int a) {
    return a % 5;
}

int prepare(char str[], int size) {
    if (size % 2 != 0) {
        str[size++] = 'z';
        str[size] = '\0';
    }
    return size;
}

void encrypt(char str[], char keyT[5][5], int size) {
    int a[4];
    for (int i = 0; i < size; i += 2) {
        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        } else if (a[1] == a[3]) {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        } else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void decrypt(char str[], char keyT[5][5], int size) {
    int a[4];
    for (int i = 0; i < size; i += 2) {
        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][mod5(a[1] + 4)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 4)];
        } else if (a[1] == a[3]) {
            str[i] = keyT[mod5(a[0] + 4)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 4)][a[1]];
        } else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void playfairCipher(char str[], char key[], bool encryptFlag) {
    int ks, ps;
    char keyT[5][5];

    ks = strlen(key);
    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);

    ps = strlen(str);
    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);
    ps = prepare(str, ps);

    generateKeyTable(key, ks, keyT);

    if (encryptFlag) {
        encrypt(str, keyT, ps);
    } else {
        decrypt(str, keyT, ps);
    }
}

int main() {
    char str[SIZE], key[SIZE];
    int choice;

    cout << "Welcome!!!" << endl
         << "Please enter your choice:" << endl
         << "1 for ENCRYPTION" << endl
         << "2 for DECRYPTION" << endl;
    cin >> choice;
    cin.ignore(); // To ignore the newline character left in the input buffer

    cout << "Enter the input string: " << endl;
    cin.getline(str, SIZE);

    cout << "Enter the required key: " << endl;
    cin.getline(key, SIZE);

    if (choice == 1) {
        playfairCipher(str, key, true);
        cout << "Encrypted text: " << str << endl;
    } else if (choice == 2) {
        playfairCipher(str, key, false);
        cout << "Decrypted text: " << str << endl;
    } else {
        cout << "Enter valid input" << endl;
    }

    return 0;
}
