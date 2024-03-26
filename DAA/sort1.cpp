#include<iostream>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<iomanip>
#include<string>

#define MAX 10000

using namespace std;

void writeThefile(string file, int n)
{
    // Seed for random number generation
    srand(time(0));

    // Open the file for writing
    ofstream myFile(file);

    // Check if the file is opened successfully
    if (!myFile.is_open())
    {
        cout << "Error is opening file";
        return;
    }

    // Generate and write random numbers to the file
    for (int i = 0; i < n; i++)
    {
        myFile << rand() % MAX << "\n";
    }

    // Close the file
    myFile.close();
}

// Function to read numbers from a file into an array
int readThefile(string file, int arr[])
{
    // Open the file for reading
    ifstream myFile(file);

    // Variables for reading from the file
    int i = 0, j = 0;

    // Check if the file is opened successfully
    if (!myFile.is_open())
    {
        cerr << "Error opening file: " << file << endl;
        return 0;
    }

    // Read numbers from the file into the array
    while (myFile >> i)
    {
        arr[j] = i;
        j++;
    }

    // Close the file
    myFile.close();
}

void insertionSort( int arr[],int n){
    for(int i=0;i<i-1;i++){
        int j = i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j-1],arr[j]);
        }
    }
}

void merge(int left[],int n1,int right[],int n2,int arr[],int n){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
        if(left[i]<right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<n1){                            
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = right[j];
        j++;
        k++;
    }
}

int mergeSort(int arr[],int n){
    if(n>1){
        int mid = n/2;
        int left[mid],right[n-mid];
        for(int i=0;i<mid;i++){
            left[i] = arr[i];
        }
        for(int i=mid;i<n;i++){
            right[i-mid] = arr[i];
        }
        mergeSort(left,mid);
        mergeSort(right,n-mid);
        merge(left,mid,right,n-mid,arr,n);
    }
}

int main()
{
    // no. of random no. to be generated
    int n = 500;
    int choice;
    cout << "1.Insertion sort\n2.Merge sort\nEnter : ";
    cin >> choice;

    if (choice == 1)
    {

        while (n >= 500 & n <= 5000)
        {

            int arr[n];

            string randomNumberFile = "unsorted.txt";
            string sortedFile = "Insertionsorted.txt";

            // Generate random numbers and write them to the file
            writeThefile(randomNumberFile, n);

            // Read the file into the array and print the original array
            readThefile(randomNumberFile, arr);
            // cout << "Original Array: \n";
            // printArray(arr, n);

            // Perform Selection Sort on the array

            // Perform bubbleSort Sort on the array
            clock_t start_s, end_s;
            float total_s;

            start_s = clock();
            insertionSort(arr, n);
            end_s = clock();
            total_s = ((float)(end_s - start_s)) / CLOCKS_PER_SEC;
            cout << "n = "<< n << " ";
            cout << "Insertion sort " << setprecision(10) << total_s << endl;

            // Update the file with the sorted array

            // updateFile(arr, sortedFile, n);
            n = n + 500;
        }
    }
    else if (choice == 2)
    {
        while (n >= 500 & n <= 5000)
        {

            int arr[n];

            string randomNumberFile = "unsorted.txt";
            string sortedFile = "MergeSorted.txt";

            // Generate random numbers and write them to the file
            writeThefile(randomNumberFile, n);

            // Read the file into the array and print the original array
            readThefile(randomNumberFile, arr);
           
            clock_t start_s, end_s;
            float total_s;

            start_s = clock();
            mergeSort(arr, n);
            end_s = clock();
            total_s = ((float)(end_s - start_s)) / CLOCKS_PER_SEC;
             cout << "n = "<< n << " ";
            cout << "Merge sort " << setprecision(10) << total_s << endl;

           
            // Update the file with the sorted array
            // updateFile(arr, sortedFile, n);

            n = n + 500;
        }
    }
}