// Description
// Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.
// Input
// Line 1: contains an integer n (1 <= n <= 20)
// Output
// Write binary sequences in a lexicographic ordder, eac sequence in a line

// Example
// Input
// 3
// Output
// 000
// 001
// 010
// 011
// 100
// 101
// 110
// 111

#include <iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i];
    }
    cout << endl;
}
void binaryGeneration(int arr[], int n, int i){
    if(i == n){
        printArray(arr, n);
        return;
    }
    arr[i] = 0;
    binaryGeneration(arr, n, i+1);
    arr[i] = 1;
    binaryGeneration(arr, n, i+1);
}
int main(){
    int n; cin >> n;
    int arr[n];
    binaryGeneration(arr, n, 0);
    return 0;
}
