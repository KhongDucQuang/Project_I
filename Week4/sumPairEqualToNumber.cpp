// Description
// Cho dãy a1, a2, ..., an trong đó các phần tử đôi một khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

// Dữ liệu
// Dòng 1: ghi n và M (1 <= n, M <= 1000000)
// Dòng 2: ghi a1, a2, ..., an
// Kết quả
// Ghi ra giá trị Q

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    unordered_map<int, bool> myMap;
    int n, M; cin >> n >> M;
    int k;
    int res = 0;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        cin >> k;
        myMap[k] = true;
        arr.push_back(k);
    }
    for(int i = 0; i < n; i++){
        if(myMap[M - arr[i]] == true){
            res++;
        }
    }
    cout << res/2;
    return 0;
}