#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#define MAX 10000

using namespace std;

// Function to generate random numbers and write them to a file
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

// Function to update a file with the content of an array
int updateFile(int arr[], string file, int n)
{
    // Open the file for writing
    ofstream outputFile(file);

    // Check if the file is opened successfully
    if (outputFile.is_open())
    {
        // Write the content of the array to the file
        for (int i = 0; i < n; i++)
        {
            outputFile << arr[i] << "\n";
        }

        // Notify that the array is saved to the file
        cout << "Sorted array saved to: " << file << endl;

        // Close the file
        outputFile.close();
    }
}

// Function to print the content of an array
int printArray(int arr[], int n)
{
    cout << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to swap two elements
int swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Function to perform Bubble Sort on an array
int bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // cout << "Pass" << i + 1 << endl;
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Print the array during each swap for visualization
                // printArray(arr, n);
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform Selection Sort on an array
int selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // cout << "Pass" << i + 1 << endl;
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // Print the array during each swap for visualization
        // printArray(arr, n);
        swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    // no. of random no. to be generated
    int n = 500;
    int choice;
    cout << "1.Bubble sort\n2.Selection sort\nEnter : ";
    cin >> choice;

    if (choice == 1)
    {

        while (n >= 500 & n <= 5000)
        {

            int arr[n];

            string randomNumberFile = "unsorted.txt";
            string sortedFile = "Bubblesorted.txt";

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
            bubbleSort(arr, n);
            end_s = clock();
            total_s = ((float)(end_s - start_s)) / CLOCKS_PER_SEC;
            cout << "n = "<< n << " ";
            cout << "Bubble sort " << setprecision(10) << total_s << endl;

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
            string sortedFile = "selectionSorted.txt";

            // Generate random numbers and write them to the file
            writeThefile(randomNumberFile, n);

            // Read the file into the array and print the original array
            readThefile(randomNumberFile, arr);
           
            clock_t start_s, end_s;
            float total_s;

            start_s = clock();
            selectionSort(arr, n);
            end_s = clock();
            total_s = ((float)(end_s - start_s)) / CLOCKS_PER_SEC;
             cout << "n = "<< n << " ";
            cout << "Selection sort " << setprecision(10) << total_s << endl;

           
            // Update the file with the sorted array
            // updateFile(arr, sortedFile, n);

            n = n + 500;
        }
    }
}