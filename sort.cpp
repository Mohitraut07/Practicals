#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

// int bubbleSort(FILE * fptr){
//     ifstream myfile("sample.txt");
//     FILE * fptr;
//     fptr = fopen("/Users/MOHIT/Desktop/c++/sample.txt","r");
// }

int main(){
    srand((unsigned) time(NULL));
    int a[5];
    ofstream myfile("sample.txt");
    FILE * fptr;
    fptr = fopen("/Users/MOHIT/Desktop/c++/sample.txt","w");
    for(int i=1;i<=1000;i++){
        int random = rand();
        cout << random << endl;
        a[i] = random;
        fprintf(fptr,"%d\n",random);

    }

    fclose(fptr);
    return 0;
}