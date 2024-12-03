// Description
// Given a TEXT, write a program that converts the TEXT to upper-case. 

// Input
// The TEXT

// Output
// The TEXT in which characters are converted into upper-case
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string text;
    std::getline(std::cin, text, '\0'); 
    for (char &c : text) {
        c = std::toupper(c);
    }
    std::cout << text << std::endl;
    return 0;
}
