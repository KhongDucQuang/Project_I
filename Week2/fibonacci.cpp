// Description
// Given a fibonacci sequence a[0], a[1], a[2], ... in which:  a[0] = 0, a[1] = 1, a[n] = a[n-1] + a[n-2], for all n >= 2
// Given  positive integer n, compute a[n-1].
// Input
// Line 1: contains a positive integer n (2 <= n <= 21)
// Output
// Write a[n-1]
// Example
// Input
// 9
// Output
// 21
#include <iostream>
int fibonacii(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacii(n-1) + fibonacii(n-2);
}
int main(){
    int n; std::cin >> n;
    std::cout << fibonacii(n-1);
    return 0;
}