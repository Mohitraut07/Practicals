#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>

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

    return j; // Return the number of elements read
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    // no. of random no. to be generated
    int n = 500;
    int choice;
    cout << "1.Heap sort\n2.Quick sort\nEnter : ";
    cin >> choice;

    while (n >= 500 && n <= 5000)
    {

        int arr[n];

        string randomNumberFile = "unsorted.txt";
        string sortedFile;

        switch (choice)
        {
        case 1:
            sortedFile = "HeapSorted.txt";
            heapSort(arr, n);
            break;
        case 2:
            sortedFile = "QuickSorted.txt";
            quickSort(arr, 0, n - 1);
            break;
        default:
            cout << "Invalid choice" << endl;
            return 0;
        }

        // Generate random numbers and write them to the file
        writeThefile(randomNumberFile, n);

        // Read the file into the array and print the original array
        // int size = readThefile(randomNumberFile, arr);
        // cout << "Original Array: \n";
        // for (int i = 0; i < size; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        clock_t start_s, end_s;
        float total_s;

        start_s = clock();
        // Perform sorting based on the choice
        switch (choice)
        {
        case 1:
            heapSort(arr, n);
            break;
        case 2:
            quickSort(arr, 0, n - 1);
            break;
        }

        end_s = clock();
        total_s = ((float)(end_s - start_s)) / CLOCKS_PER_SEC;

        // Print the sorted array
        // cout << "Sorted Array: \n";
        // for (int i = 0; i < size; i++)
        // {
        //     cout << arr[i] << " ";
        // }
        // cout << endl;

        // Print the time taken for sorting
        cout << "Time taken for sorting: " << setprecision(10) << total_s << endl;

        n = n + 500;
    }

    return 0;
}
