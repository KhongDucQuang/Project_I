/*
Description
Given two positive integers k and n. 
Compute C(k,n) which is the number of ways to select 
k objects from a given set of n objects.
*/
#include <iostream>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 1000;

long long fac[MAX + 1];
long long invFactorial[MAX + 1];

long long power(long long n , int k){
    long long res = 1;
    while(k > 0){
        if(k % 2 == 1){
            res = (res * n) % MOD;
        }
        n = (n * n) % MOD;
        k /= 2;
    }
    return res;
}

void preprocess(){
    fac[0] = 1;
    for(int i = 1; i <= MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;

    }

    invFactorial[MAX] = power(fac[MAX], MOD - 2);
    for(int i = MAX - 1; i >= 0; i--){
        invFactorial[i] = invFactorial[i + 1]*(i + 1) % MOD;
    }
}

long long computeC_k_n(int n, int k){
    if(k > n) return 0;
    return fac[n] * invFactorial[k] % MOD * invFactorial[n - k] % MOD;
}

int main(){
    int k, n; cin >> k >> n;
    preprocess();
    cout << computeC_k_n(n, k);
    return 0;
}
