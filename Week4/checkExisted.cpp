// Description
// Cho dãy số nguyên A1, A2, . . . , An với mỗi số nguyên Ai kiểm tra xem có số Aj nào bằng Ai hay không với j<i.
// Input
// Dòng đầu chứa số n (1≤n≤100,000)
// Dòng hai chứa nn số nguyên A1, A2, ..., An (1≤Ai≤1000,000,000)
// Output
// Ghi ra n dòng, dòng thứ i in ra 1 nếu tồn tại Aj=Ai với j<i, ngược lại in ra 0.
// Example
// input
// 5
// 1 4 3 1 4
// output
// 0
// 0
// 0
// 1
// 1

#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<int, bool> myMap;
    int n; cin >> n;
    int k;
    for(int i = 0; i < n ; i++){
        cin >> k;
        if(myMap[k] == false){
            cout << 0 << endl;
            myMap[k] = true;
        } else {
            cout << 1 << endl;
        }
    }
    return 0;
}