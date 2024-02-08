#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbers(int n, const char* filename) {
    FILE* file = fopen("input.txt", "w");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    for(int i = 0; i < n; i++) {
        fprintf(file, "%d\n", rand() % 1000); // Generates numbers between 0 and 999
    }
    fclose(file);
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++)     
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

void readFromFileAndSort(const char* filename, int sortType) {
    int arr[1000]; // Adjust size as needed
    int n = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while(fscanf(file, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(file);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    if (sortType == 1) {
        selectionSort(arr, n);
        printf("Using Selection Sort\n");
    } else if (sortType == 2) {
        bubbleSort(arr, n);
        printf("Using Bubble Sort\n");
    } else {
        printf("Invalid sort type\n");
        return;
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorting took %f seconds to execute \n", cpu_time_used);
}

int main() {
    int choice;
    const char* filename = "numbers.txt";
    printf("Generating 100 random numbers...\n");
    generateRandomNumbers(100, filename);

    printf("Choose sorting algorithm:\n");
    printf("1: Selection Sort\n");
    printf("2: Bubble Sort\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    readFromFileAndSort(filename, choice);

    return 0;
}