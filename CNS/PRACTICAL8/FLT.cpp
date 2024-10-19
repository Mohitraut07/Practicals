#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n)
{
   
    return n%2 != 0;
}

// Fermat's Little Theorem: a^(p-1) % m
int Fermats_v1(int a, int p, int m)
{
    int result = 1;
    for (int i = 0; i < p-1; i++)
    {
        result = (result * a) % m;
    }
    return result;
}

// Fermat's Little Theorem alternative version
int Fermats_v2(int a, int p, int m)
{
    int result = 1;
    for (int i = 0; i < p; i++)
    {
        result = (result * a) % m;
    }
    return result;
}

int main()
{
    int a, p, m;
    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of p: ";
    cin >> p;
    cout << "Enter the value of m: ";
    cin >> m;

    if(p == -1){
        p = m - 2; // Fermat's theorem for finding modular inverse
        cout << "The output is: " << p % m << endl;
        return 0;
    }   
    else if(p < -1) {
        cout << "Invalid value of p" << endl;
        return 0;
    }

    // Check if p is prime
    if (isPrime(p))
    {
        if (a % p == 0)
        {
            cout << "Fermats_v2: " << Fermats_v2(a, p, m) << endl;
        }
        else
        {
            cout << "Fermats_v1: " << Fermats_v1(a, p, m) << endl;
        }
    }


    return 0;
}
