/*
Description
Given an integer n, write a program to generate all permutations of 
1, 2, ..., n in a lexicalgraphic order (elements of a permutation are separated 
by a SPACE character).
*/
#include <iostream>
using namespace std;
int n; 
int arr[100];
int markArr[100];
void solution(){
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Try(int k){
    for(int v = 1; v <= n; v++){
        if(!markArr[v]){
            arr[k] = v;
            markArr[v] = 1;
            if(k == n){
                solution();
            } else {
                Try(k+1);
            }
            markArr[v] = 0;
        }
    }
}

int main(){
    cin >> n;
    for(int v = 1; v <= n; v++){
        markArr[v] = 0;
    }
    Try(1);
    return 0;
}
