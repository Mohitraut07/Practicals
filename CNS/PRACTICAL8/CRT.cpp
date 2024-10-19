#include <iostream>
using namespace std;

// Function to find the smallest x that satisfies
// the system of congruences using brute force
int findMinX(int num[], int rem[], int k)
{
    int x = 1;  // Initialize result

    // As per the Chinese remainder theorem,
    // this loop will always break.
    while (true)
    {
        // Check if remainder of x % num[j] is
        // rem[j] or not (for all j from 0 to k-1)
        int j;
        for (j = 0; j < k; j++)
            if (x % num[j] != rem[j])
                break;

        // If all remainders matched, we found x
        if (j == k)
            return x;

        // Else try the next number
        x++;
    }
}

// Driver method
int main()
{
    int k;  // Number of equations (moduli)
    
    // Taking input from user
    cout << "Enter the number of moduli (k): ";
    cin >> k;

    int num[k], rem[k];

    // Taking moduli and remainders from user
    for (int i = 0; i < k; i++)
    {
        cout << "Enter modulus num[" << i + 1 << "]: ";
        cin >> num[i];
        cout << "Enter remainder rem[" << i + 1 << "]: ";
        cin >> rem[i];
    }

    // Find and print the smallest x satisfying all congruences
    int result = findMinX(num, rem, k);
    cout << "The smallest x that satisfies the system is: " << result << endl;

    return 0;
}
