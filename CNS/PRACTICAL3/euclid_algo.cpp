#include <iostream>

using namespace std;

// Function for Euclid's Algorithm to find the GCD
int euclidGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function for Extended Euclidean Algorithm
void extendedEuclidean(int a, int b, int &s, int &t, int &gcd) {
    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;

    cout << "\nStep-by-Step Calculation (Extended Euclidean Algorithm):\n";
    cout << "q \t| r1 \t| r2 \t| r \t| s1 \t| s2 \t| s \t| t1 \t| t2 \t| t \t| \n";
    cout << "----------------------------------------------------------------------------------\n";

    while (r2 > 0) {
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
}

// Function to verify the GCD
bool verifyGCD(int a, int b, int s, int t, int gcd) {
    return gcd == (s * a + t * b);
}

int main() {
    int a, b, s, t, gcd;
    int choice;

    cout << "Welcome to the GCD Calculation Program!\n";
    cout << "This program will help you find the GCD using either Euclid's or Extended Euclidean algorithms.\n\n";

    cout << "Enter value of A: ";
    cin >> a;

    cout << "Enter value of B: ";
    cin >> b;

    cout << "\nChoose the algorithm:\n";
    cout << "1. Euclid's Algorithm\n";
    cout << "2. Extended Euclidean Algorithm\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Calculate GCD using Euclid's Algorithm
            gcd = euclidGCD(a, b);
            cout << "\nGCD of " << a << " and " << b << " using Euclid's Algorithm is: " << gcd << "\n";
            break;

        case 2:
            // Calculate GCD using Extended Euclidean Algorithm
            extendedEuclidean(a, b, s, t, gcd);
            cout << "\nGCD of " << a << " and " << b << " using Extended Euclidean Algorithm is: " << gcd << "\n";
            // Verify the GCD result using the relationship: gcd = s*a + t*b
            if (verifyGCD(a, b, s, t, gcd)) {
                cout << "\nVerification successful: " << s << " * " << a << " + " << t << " * " << b << " = " << gcd << "\n";
            } else {
                cout << "\nVerification failed: The computed GCD does not satisfy the equation.\n";
            }
            break;

        default:
            cout << "Invalid choice! Please run the program again and choose either 1 or 2.\n";
            return 1;
    }

    cout << "\nThank you for using the GCD Calculation Program!\n";
    return 0;
}
