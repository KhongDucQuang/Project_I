// Description
// Given a time moment which is a string under the format hh:mm:ss (in which hh (0 <= hh <= 23) is the hour, mm (0 <= mm <= 59) is the minute, and ss (0 <= ss <= 59) is the second). Convert this time moment in seconds (result = hh*3600 + mm*60 + ss).
// Input
// Line 1: contains a string s representing the time moment.  
// Output
// if s is not under the format hh:mm:ss, then write INCORRECT. Otherwise, write value converted.

// Example
// Input
// 13:05:26

// Output
// 47126


// Input
// 13:05:6

// Output
// INCORRECT 

// Input
// 13:05 26

// Output
// INCORRECT
#include <iostream>
using namespace std;
int main(){
    string s; cin >> s;
    if(s.length() != 8 || s[2] != ':' || s[5] != ':'){
        cout << "INCORRECT";
        return 0;
    }
    int hour = (s[0] - '0')*10 + (s[1] -'0');
    if(hour < 0 || hour > 23){
        cout << "INCORRECT";
        return 0;
    }
    int minute = (s[3] - '0')*10 + (s[4] - '0');
    if(minute < 0 || minute > 59){
        cout << "INCORRECT";
        return 0;
    }
    int second = (s[6] - '0')*10 + (s[7] - '0');
    if(second < 0 || second > 59){
        cout << "INCORRECT";
        return 0;
    }
    cout << hour * 3600 + minute*60 +second;
    return 0;
}
