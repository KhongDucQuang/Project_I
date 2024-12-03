// Description
// Given an integer n, write a program that generates all binary sequences without consecutive 11 in a lexicographic order.
// Input
// Line 1: contains an integer n (1 <= n <= 20)
// Output
// Write binary sequences in a lexicographic order, each sequence in a line
// Example
// Input
// 3
// Output
// 000
// 001
// 010
// 100
// 101
/*
Description
Given an integer n, write a program that generates all binary sequences 
without consecutive 11 in a lexicographic order.
Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic order, each sequence in a line
*/
#include <iostream>
using namespace std;
int n;
int arr[100];
void solution(){
    for(int i = 1; i <= n; i++){
        cout << arr[i];
    }
    cout << endl;
}
bool check(int v, int k){
    if(v == 1 && arr[k-1] == 1){
        return false;
    }
    return true;
}
void Try(int k){
    for(int v = 0; v <= 1; v++){
        if(check(v, k)){
            arr[k] = v;
            if(k == n){
                solution();
            } else {
                Try(k+1);
            }
        }
    }
}
int main(){
    cin >> n;
    Try(1);
    return 0;
}
