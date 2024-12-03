// Description
// Given a date which is a string under the format YYYY-MM-DD (in which YYYY is the year, MM is the month (the month í from 1 to 12), and DD is the date (the date is from 1 to 31)). Extract the year, month and date.
// Input
// Line 1: contains a string s  
// Output
// if s is not under the format YYYY-MM-DD, then write INCORRECT. Otherwise, write year, month, and date separated by a SPACE character

// Example
// Input
// 2023-10-04
// Output
// 2023 10 4


// Input
// 2023-10-4
// Output
// INCORRECT 

// Input
// 2023-10 04
// Output
// INCORRECT
#include <iostream>
using namespace std;
int main(){
    string s; cin >> s;
    if(s.length() != 10 || s[4] != '-' || s[7] != '-'){
        cout << "INCORRECT";
        return 0;
    }
    int month = (s[5] - '0')*10 + (s[6] - '0');
    if(month < 1 || month > 12){
        cout << "INCORRECT";
        return 0;
    }
    int day = (s[8] - '0')*10 + (s[9] - '0');
    if(day < 1 || day > 31){
        cout << "INCORRECT";
        return 0;
    }

    cout << s[0] << s[1] << s[2] << s[3] << " " << month << " " << day;
    
}
