// Description
// Given a positive integer n, find all integer having 3 digits which is divisible by n.
// Input
// Line 1: contains a positive integer n (1 <= n <= 999)
// Output
// Write the sequence of numbers found (elements are separated by a SPACE character)
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n; cin >> n;
    int start = (100 + n - 1) / n * n;  

    for (int i = start; i <= 999; i += n) {
        cout << i << " ";
    }
    return 0;
}
