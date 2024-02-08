#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                swap(&arr[j + 1], &arr[j]);
            }
        }
    }
}

void selectioSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

void generateRandom(int arr[], int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % n;
    }
}

void saveToFile(int arr[], int n)
{
    fstream file;

    file.open("random.txt", ios::out);
    for (int i = 0; i < n; i++)
    {
        file << arr[i] << " ";
    }
}

void readFile(int arr[], int n)
{
    fstream file;
    file.open("random.txt", ios::in);
    for (int i = 0; i < n; i++)
    {
        file >> arr[i];
    }
}

int main()
{
    int bubbleSortTime[10], selectionSortTime[10];
    for (int i = 1; i <= 10; i++)
    {

        int n = rand() % 10000;
        int arr[n];

        // generating random numbers and saving to file
        generateRandom(arr, n);
        // saving array to file
        saveToFile(arr, n);

        // using bubble sort
        readFile(arr, n);
        auto start = high_resolution_clock::now();
        bubbleSort(arr, n);
        bubbleSortTime[i - 1] = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();

        // using selection sort
        readFile(arr, n);
        start = high_resolution_clock::now();
        selectioSort(arr, n);
        selectionSortTime[i - 1] = duration_cast<milliseconds>(high_resolution_clock::now() - start).count();
    }
    cout << "Bubble Sort Time: ";
    for (int i = 0; i < 10; i++)
    {
        cout << bubbleSortTime[i] << " ";
    }

    cout << "\nSelection Sort Time: ";
    for (int i = 0; i < 10; i++)
    {
        cout << selectionSortTime[i] << " ";
    }
    return 0;
}