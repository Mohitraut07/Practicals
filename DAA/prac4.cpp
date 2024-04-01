#include <iostream>
using namespace std;

class Jobs
{
public:
    char id;
    int deadLine;
    int profit;
};

bool comp(Jobs j1,Jobs j2){
    return (j1.profit>j2.profit);
}

int min(int a, int b){
   return (a<b)?a:b;
}

int main()
{
    Jobs jobs[] = {
        {'a', 2, 100},
        {'b', 2, 20},
        {'c', 1, 40},
        {'d', 3, 35},
        {'e', 1, 25}};

        int n=sizeof(jobs)/sizeof(jobs[0]);//size of jobs array

        sort (jobs,jobs+n,comp);//sort jobs on profit
        int jobSeq[n];//store result sequence
        bool slot[n];// To keep track of free time slot
        for(int i=0;i<n;i++)
            slot[i] = false;//initially all slots are free
        for(int i=0;i<n;i++){
            for(int j=min(n,jobs[i].deadLine)-1;j>=0;j--){
                if(slot[j] == false){
                    jobSeq[j] = i;
                    slot[j] = true;
                    break;
                }
            }
        }
        // cout << jobs[0].profit << endl;
        // cout << n << endl;
        for(int i=0;i<n;i++){
            if(slot[i]){
                cout <<"Execution sequence: "<< jobs[jobSeq[i]] << endl;
            }
        }
    return 0;
}