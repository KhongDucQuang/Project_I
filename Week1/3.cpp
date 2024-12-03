// Description
// Given a sequence of integers a1, a2, ..., an. Compute the sum Q of elements of this sequence.
// Input
// Line 1: contains n (1 <= n <= 1000000)
// Line 2: contains a1, a2, ..., an (-10000 <= ai <= 10000)
// Output
// Write the value of Q

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<long long> arr;
    int n; cin >> n;
    long long sum = 0;
    long long k;
    for(int i = 0; i < n; i++){
        cin >> k;
        sum += k;
    }
    cout << sum;
}
