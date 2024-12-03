// Description
// Perform a sequence of operations over a queue, each element is an integer:
// PUSH v: push a value v into the queue
// POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
// Input
// Each line contains a command (operration) of type
// PUSH  v
// POP
// Output
// Write the results of POP operations (each result is written in a line)
#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> my_queue;
    string cmd;
    while(true){
        cin >> cmd;
        if(cmd == "#") break;
        if(cmd == "PUSH"){
            int k; cin >> k;
            my_queue.push(k);
        } else if(cmd == "POP"){
            if(my_queue.empty()){
                cout << "NULL" << endl;
            } else {
                cout << my_queue.front() << endl;
                my_queue.pop();
            }
        }
    }
    return 0;
}
