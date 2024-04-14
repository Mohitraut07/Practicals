#include <iostream>
#include <algorithm>
using namespace std;

class Jobs
{
public:
    char id;
    int deadLine;
    int profit;
};

bool comp(Jobs j1, Jobs j2)
{
    return (j1.profit > j2.profit);
}

int main()
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    Jobs jobs[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the job id: ";
        cin >> jobs[i].id;
        cout << "Enter the deadline: ";
        cin >> jobs[i].deadLine;
        cout << "Enter the profit: ";
        cin >> jobs[i].profit;
    }

    sort(jobs, jobs + n, comp); // Sort jobs on profit
    int jobSeq[n];             // Store result sequence
    bool slot[n];              // To keep track of free time slot
    for (int i = 0; i < n; i++)
        slot[i] = false; // Initially all slots are free
    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, jobs[i].deadLine) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                jobSeq[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Execution sequence: ";
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << jobs[jobSeq[i]].id << " ";
        }
    }
    cout << endl;

    return 0;
}


       /* {'a', 2, 100},
        {'b', 2, 20},
        {'c', 1, 40},
        {'d', 3, 35},
        {'e', 1, 25}*/