#include <iostream>
using namespace std;

struct Memory {
    int a, b, c;
};

Memory all[5];
Memory ava;
Memory need[5];

int main() {
    Memory max[5];
    int size;
    cout << "Enter the size: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout << "Enter the allocated resources for process " << i + 1 << ": ";
        cin >> all[i].a >> all[i].b >> all[i].c;
        cout << "Enter the max resources for process " << i + 1 << ": ";
        cin >> max[i].a >> max[i].b >> max[i].c;
    }
    cout << "Enter the available resources: ";
    cin >> ava.a >> ava.b >> ava.c;

    int completed[5] = {0}; // Array to track completed processes
    int flag = 1;

    while (flag) {
        flag = 0;

        for (int i = 0; i < size; i++) {
            if (completed[i] == 0) {
                if (need[i].a <= ava.a && need[i].b <= ava.b && need[i].c <= ava.c) {
                    ava.a += all[i].a;
                    ava.b += all[i].b;
                    ava.c += all[i].c;
                    completed[i] = 1; // Mark process as completed

                    cout << "Process " << i + 1 << " enters execution." << endl;
                    flag = 1;
                }
            }
        }
    }

    // Check if all processes are completed
    for (int i = 0; i < size; i++) {
        if (completed[i] == 0) {
            cout << "Unsafe state! Not all processes can be executed." << endl;
            return 0;
        }
    }

    cout << "Safe state! All processes have been executed." << endl;

    return 0;
}
