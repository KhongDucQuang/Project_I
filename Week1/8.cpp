// Description
// Given an equation ax^2 + bx + c = 0. Find solution to the given equation.
// Input
// Line 1 contains 3 integers a, b, c 
// Output
// Write NO SOLUTION if the given equation has no solution 
// Write x0 (2 digits after the decimal point) if the given equation has one solution x0 
// Write x1 and x2 with x1 < x2 (2 digits after the decimal point) if the given equation has two distinct solutions x1, x2 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int a, b, c; cin >> a >> b >> c;
    int delta = b*b - 4*a*c;
    if(delta < 0) cout << "NO SOLUTION";
    else if(delta == 0) cout << fixed << setprecision(2) << (0-b)*1.0/(2*a);
    else {
        cout << fixed << setprecision(2) << (0 - b - sqrt(delta))/(2*a) << " ";
        cout << fixed << setprecision(2) << (0 - b + sqrt(delta))/(2*a);
    }
}
