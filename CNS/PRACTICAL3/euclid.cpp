#include <iostream>
using namespace std;

void euclidean(int a, int b)
{
    int r1, r2;
    r1 = a;
    r2 = b;
    cout << "r1\t|" << "r2\t|" << "r\t|" << "q\t|" << endl;
    cout << "---------------------------------\n";

    while (r2 > 0)
    {
        int r, q;
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        cout << r1 << "\t|" << r2 << "\t|" << r << "\t|" << q << "\t|" << endl;
    }
    cout << endl;
    cout << "GCD of " << a << " and " << b << " using Euclid's Algorithm is : " << r1 << endl;
}

bool verifyGCD(int a, int b, int s, int t, int gcd) {
    return gcd == (s * a + t * b);
}

void extended_euclidean(int a, int b)
{

    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    int gcd , s, t;

    cout << "\nStep-by-Step Calculation (Extended Euclidean Algorithm):\n";
    cout << "q \t| r1 \t| r2 \t| r \t| s1 \t| s2 \t| s \t| t1 \t| t2 \t| t \t| \n";
    cout << "----------------------------------------------------------------------------------\n";

    while (r2 > 0)
    {
        int q = r1 / r2;

        int r = r1 - (q * r2);
        r1 = r2;
        r2 = r;

        s = s1 - (q * s2);
        s1 = s2;
        s2 = s;

        t = t1 - (q * t2);
        t1 = t2;
        t2 = t;

        cout << q << " \t| " << r1 << " \t| " << r2 << " \t| " << r << " \t| " << s1 << " \t| " << s2 << " \t| " << s << " \t| " << t1 << " \t| " << t2 << " \t| " << t << " \t|\n";
    }

    gcd = r1;
    s = s1;
    t = t1;
    if (verifyGCD(a, b, s, t, gcd))
    {
        cout << "\nVerification successful: " << s << " * " << a << " + " << t << " * " << b << " = " << gcd << "\n";
    }
    else
    {
        cout << "\nVerification failed: The computed GCD does not satisfy the equation.\n";
    }
}

int main()
{
    int num1, num2, choice, result;
    cout << "Welcome to GCD Calculation program!" << '\n';
    cout << "This program will help you find the GCD using either Euclid's of Extended Euclidean algorithm." << "\n";
    cout << endl;

    cout << "Enter value of A: ";
    cin >> num1;
    cout << "Enter value of B: ";
    cin >> num2;

    cout << "Choose the algorithm:" << '\n';
    cout << "1. Euclid's Algorithm" << '\n';
    cout << "2. Extended Euclidean Algorithm" << '\n';
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1)
    {
        euclidean(num1, num2);
    }
    else if (choice == 2)
    {
        extended_euclidean(num1, num2);
    }
    else
    {
        cout << "Please enter a valid choice." << endl;
        
    }
    cout << "Thank you for using GCD Calculator." << endl;
    return 0;
}