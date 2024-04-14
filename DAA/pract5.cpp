#include <iostream>
using namespace std;

class Item
{
public:
    char id;
    int weight;
    int profit;
};

bool maxComp(Item o1, Item o2)
{
    return o1.profit > o2.profit;
}
bool minComp(Item o1, Item o2)
{
    return o1.weight < o2.weight;
}

bool comp(Item a, Item b){
    double r1 = (double)a.profit/a.weight;
    double r2 = (double)b.profit/b.weight;

    return r1>r2;
}

double fractionalKnapsack(int W, Item arr[], int N) {
    sort(arr, arr + N, comp); // Sort items by profit/weight ratio in descending order
    double finalvalue = 0.0;

    for (int i = 0; i < N; i++) {
        cout << "Considering item " << arr[i].id << " with weight " << arr[i].weight << " and profit " << arr[i].profit << endl;
        if (arr[i].weight <= W) {
            // Add the entire item to the knapsack
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
            cout << "Added item " << arr[i].id << " completely to the knapsack" << endl;
        } else {
            // Add a fraction of the item to the knapsack
            double fraction = (double)W / arr[i].weight;
            finalvalue += arr[i].profit * fraction;
            cout << "Added a fraction of item " << arr[i].id << " to the knapsack" << endl;
            break; // No need to continue since knapsack is full
        }
    }
    return finalvalue;
}

double maxProfitKnapsack(int W, Item arr[], int N) {
    sort(arr, arr + N, maxComp); // Sort items by profit in descending order
    double finalvalue = 0.0;

    for (int i = 0; i < N; i++) {
        cout << "Considering item " << arr[i].id << " with weight " << arr[i].weight << " and profit " << arr[i].profit << endl;
        if (arr[i].weight <= W) {
            // Add the entire item to the knapsack
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
            cout << "Added item " << arr[i].id << " completely to the knapsack" << endl;
        } else {
            // Add a fraction of the item to the knapsack
            double fraction = (double)W / arr[i].weight;
            finalvalue += arr[i].profit * fraction;
            cout << "Added a fraction of item " << arr[i].id << " to the knapsack" << endl;
            W -= arr[i].weight * fraction; // Update the remaining weight
            break; // No need to continue since knapsack is full
        }
    }
    return finalvalue;
}

double minWeightKnapsack(int W, Item arr[], int N) {
    sort(arr, arr + N, minComp); // Sort items by weight in ascending order
    double finalvalue = 0.0;

    for (int i = 0; i < N; i++) {
        cout << "Considering item " << arr[i].id << " with weight " << arr[i].weight << " and profit " << arr[i].profit << endl;
        if (arr[i].weight <= W) {
            // Add the entire item to the knapsack
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
            cout << "Added item " << arr[i].id << " completely to the knapsack" << endl;
        } else {
            // Add a fraction of the item to the knapsack
            double fraction = (double)W / arr[i].weight;
            finalvalue += arr[i].profit * fraction;
            cout << "Added a fraction of item " << arr[i].id << " to the knapsack" << endl;
            W -= arr[i].weight * fraction; // Update the remaining weight
            break; // No need to continue since knapsack is full
        }
    }
    return finalvalue;
}

int main()
{
    int W,choice,n;
    double res;
    cout << "Enter the weight value:"<< endl;
    cin>> W;
    cout << "Enter the number of items:"<< endl;
    cin>> n;
    
    class Item arr[n];

    for(int i=0;i<n;i++){
        cout << "Enter the item name:";
        cin >> arr[i].id;
        cout << "Enter the item weight:";
        cin >> arr[i].weight;
        cout << "Enter the item profit:";
        cin >> arr[i].profit;
    }

    cout << "The Knapsack Problem you want to implement:\n 1.Max Profit\n2.Min Weight\n3.Fractional Knapsack\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        res = maxProfitKnapsack(W,arr,n);
        cout << res;
        break;
    case 2:
        res = minWeightKnapsack(W,arr,n);
        cout << res;
        break;
    case 3:
        res = fractionalKnapsack(W,arr,n);
        cout << res;
        break;
    
    default:
        break;
    }
    return 0;
}
