#include<iostream>
using namespace std;

int insertionSort( int arr[],int n){
    for(int i=0;i<i-1;i++){
        int j = i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j-1],arr[j]);
        }
    }
}

int main(){

    return 0;
}