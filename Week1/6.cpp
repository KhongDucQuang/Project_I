// Description
// Given a Text, write a prorgam to count the number Q of words (ignore characters SPACE, TAB, LineBreak) of this Text

// Input
// The Text

// Output
// Write the number Q of words
#include <iostream>
#include <string>
using namespace std;

int main() {
    std::string text;
    std::getline(std::cin, text, '\0'); 

    int count = 0; 
    bool inWord = false; 

    for (char c : text) { 
        if (c != ' ' && c != '\t' && c != '\n') { 
            if (!inWord) { 
                count++; 
                inWord = true; 
            }
        } else {
            inWord = false; 
        }
    }

    std::cout << count << std::endl;
    return 0;
}
