// Description
// Given a family tree represented by child-parent (c,p) relations in which c is a child of p. Perform queries about the family tree:
// descendants <name>: return number of descendants of the given <name>
// generation <name>: return the number of generations of the descendants of the given <name>

// Note that: the total number of people in the family is less than or equal to 10
// 4
// Input
// Contains two blocks. The first block contains information about child-parent, including lines (terminated by a line containing ***), each line contains: <child> <parent> where <child> is a string represented the name of the child and <parent> is a string represented the name of the parent. The second block contains lines (terminated by a line containing ***), each line contains two string <cmd> and <param> where <cmd> is the command (which can be descendants or generation) and <param> is the given name of the person participating in the  query.
// Output
// Each line is the result of a corresponding query.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, vector<string>> faTree;

int countDescendants(const string& person){
    if(faTree.find(person) == faTree.end()){
        return 0;
    }
    int count = 0;
    for(const string& child : faTree[person]){
        count += 1 + countDescendants(child);
    }
    return count;
}

int countGenerations(const string& person){
    if(faTree.find(person) == faTree.end()){
        return 0;
    }
    int maxGen = 0;
    for(const string& child : faTree[person]){
        maxGen = max(maxGen,1+countGenerations(child));
    }
    return maxGen;
}
int main(){
    string child, parent;
    while(true){
        cin >> child;
        if(child == "***") break;
        cin >> parent;
        faTree[parent].push_back(child);
    }

    string cmd, param;
    while(true){
        cin >> cmd;
        if(cmd == "***") break;
        cin >> param;
        if(cmd == "descendants"){
            cout << countDescendants(param) << endl;
        } else if(cmd == "generation"){
            cout << countGenerations(param) << endl;
        }
    }
    return 0;
}
