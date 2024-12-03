// Description
// Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
// Given positive integers k and m. Compute the number Q of k-subsequences such that the weight is even.
// Input
// Line 1: contains 2 positive integers n, k (1 <= n <= 100000, 1 <= k <= n/2)
// Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
// Output
// Write the value Q
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> S(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    S[0] = arr[0];
    // cout << S[0] << " ";
    for(int i = 1; i < n; i++){
        S[i] = S[i-1] + arr[i];
        // cout << S[i] << " ";
    }
    
    int res = 0;
    int left = 0;
    int right = left + k - 1;
    for(int i = 0; i <= n - k; i++) {
        int sum = (i == 0) ? S[i + k - 1] : S[i + k - 1] - S[i - 1];
        if (sum % 2 == 0) {
            res++;
        }
    }

    cout << res;
    return 0;
}
