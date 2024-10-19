#include<iostream>
using namespace std;

// Function to compute GCD using Euclidean Algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Euler's Totient Function: calculates φ(n)
int Phi(int n)
{
    int result = n;  // Start with n
    for (int i = 2; i * i <= n; i++)  // Iterate over possible factors
    {
        if (n % i == 0)  // If i is a factor
        {
            // Divide out all factors of i from n
            while (n % i == 0)
                n /= i;
            // Apply the formula: result *= (1 - 1/p) where p is a prime factor
            result -= result / i;
        }
    }
    // If n is still greater than 1, it must be prime
    if (n > 1)
        result -= result / n;

    return result;
}

// Function to perform modular exponentiation: a^b % m
int modExpo(int a, int b, int m)
{
    int result = 1;
    a = a % m;  // In case a is greater than m
    while (b > 0)
    {
        // If b is odd, multiply a with result
        if (b % 2 == 1)
            result = (result * a) % m;
        
        // Now b must be even
        b = b / 2;
        a = (a * a) % m;  // Square the base
    }
    return result;
}

// Euler's Theorem (Version 1) - Co-Prime case
int EulerV1(int a, int b, int n)
{
    if (gcd(a, n) == 1)  // Check if a and n are co-prime
    {
        int phi_n = Phi(n);  // Compute φ(n)
        b = b % phi_n;  // Reduce the exponent using φ(n)
        return modExpo(a, b, n);  // Calculate a^b % n
    }
    else
    {
        cout << "a and n are not co-prime!" << endl;
        return -1;
    }
}

// Euler's Theorem (Version 2) - Non Co-Prime case (n = p * q)
int EulerV2(int a, int k, int n)
{
    int p = 7, q = 11;  // Example for n = 77 (p = 7, q = 11)
    int phi_n = Phi(n);

    // If a is divisible by p or q, handle this case separately
    if (a % p == 0 || a % q == 0)
    {
        return a;  // For multiples of p or q, the result simplifies
    }
    else
    {
        return modExpo(a, k * phi_n + 1, n);  // Standard modular exponentiation
    }
}

// Find the multiplicative inverse of a mod n
int multiplicativeInverse(int a, int n)
{
    if (gcd(a, n) != 1)
    {
        cout << "No multiplicative inverse exists as a and n are not co-prime." << endl;
        return -1;
    }

    int phi_n = Phi(n);  // Compute φ(n)
    return modExpo(a, phi_n - 1, n);  // Calculate a^(φ(n)-1) % n
}

int main()
{
    int choice, a, n, b, k;
    
    while (true) {
        cout << "\nChoose an option: \n";
        cout << "1. Find the multiplicative inverse of a mod n\n";
        cout << "2. Apply Euler's Theorem (Version 1: Co-Prime case)\n";
        cout << "3. Apply Euler's Theorem (Version 2: Composite n = p * q)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "\nEnter the value of a: ";
            cin >> a;
            cout << "Enter the value of n: ";
            cin >> n;
            int inverse = multiplicativeInverse(a, n);
            if (inverse != -1)
                cout << "The multiplicative inverse of " << a << " mod " << n << " is: " << inverse << endl;
        } 
        else if (choice == 2) {
            cout << "\nEnter the value of a: ";
            cin >> a;
            cout << "Enter the value of b (exponent): ";
            cin >> b;
            cout << "Enter the value of n (modulus): ";
            cin >> n;
            int result = EulerV1(a, b, n);
            if (result != -1)
                cout << a << "^" << b << " mod " << n << " = " << result << endl;
        } 
        else if (choice == 3) {
            cout << "\nEnter the value of a: ";
            cin >> a;
            cout << "Enter the value of k (multiplier for φ(n)): ";
            cin >> k;
            cout << "Enter the value of n (modulus): ";
            cin >> n;
            int result = EulerV2(a, k, n);
            cout << a << "^(" << k << " * φ(n) + 1) mod " << n << " = " << result << endl;
        } 
        else if (choice == 4) {
            break;  // Exit the loop
        } 
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
