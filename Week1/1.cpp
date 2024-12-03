// Description
// Given a sequence of integers a1, a2, ..., an. Perform a sequence of queries over this sequence including:
// find-max: return the maximum element of the given sequence
// find-min: return the minimum element of the given sequence 
// sum: return the sum of the elements of the given sequence 
// find-max-segment i j: return the maximum element of the subsequence from index i to index j (i <= j)

// Input
// The first block contains the information about the given sequence with the following format:
// Line 1: contains a positive integer n (1 <= n <= 10000)
// Line 2: contains n integers a1, a2, ..., an (-1000 <= ai <= 1000)
// The first block is terminated by a character *
// The second block contains a sequence of queries defined above, each query is in a line. The second block is terminated a 3 characters ***

// Output
// Write the result of each query in a corresponding line

#include <iostream>
#include <vector>
using namespace std;
int sumArray(const vector<int> &arr){
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }
    return sum;
}
int findMax(const vector<int> &arr){
    int max = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}
int findMin(const vector<int> &arr){
    int min = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < min) min = arr[i];
    }
    return min;
}
int findMaxSegment(const vector<int> &arr, int i, int j){
    if(i == j) return arr[i-1];
    int max = arr[i-1];
    for(int k = i; k <= j-1; k++){
        if(arr[k] > max) max = arr[k];
    }
    return max;
}
int main(){
    vector<int> arr;
    int n; cin >> n;
    int k;
    for(int i = 0; i < n; i++){
        cin >> k;
        arr.push_back(k);
    }
    string delemiter;
    cin >> delemiter;
    string type;
    cin.ignore();
    while(true){
        cin >> type;
        if(type == "***") break;
        if(type == "find-max"){
            cout << findMax(arr) << endl;
        }
        else if(type == "find-min"){
            cout << findMin(arr) << endl;
        }
        else if(type == "find-max-segment"){
            int i,j; cin >> i >> j;
            cout << findMaxSegment(arr, i, j) << endl;
        }
        else if(type == "sum"){
            cout << sumArray(arr) << endl;
        }
    }
    return 0;
}
