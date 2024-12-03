// Description
// Given a string containing only characters (, ), [, ] {, }. Write a program that checks whether the string is correct in expression.
// Example
//  ([]{()}()[]): correct
//  ([]{()]()[]): incorrect
// Input
// One line contains the string (the length of the string is less than or equal to $10^6$)One line contains the string (the length of the string is less than or equal to 10
// 6
// )
// Output
// Write 1 if the sequence is correct, and write 0, otherwise
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(char a, char b){
    if(a == '(' && b == ')') return true;
    if(a == '[' && b == ']') return true;
    if(a == '{' && b == '}') return true;
    return false;
}

int solve(string s){
    int length = s.length();
    stack<char> myStack;
    for(int i = 0; i < length; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            myStack.push(s[i]);
        } else {
            if(myStack.empty()){
                return 0;
            } else {
                char c = myStack.top(); myStack.pop();
                if(!check(c, s[i])) return 0;
            }
        }
    }
    if(myStack.empty()) return 1;
    else return 0;
}
int main(){
    string s; cin >> s;
    cout << solve(s);
}
