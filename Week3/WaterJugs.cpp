// Description
// There are two jugs, a-litres jug and b-litres jug (a, b are positive integers). There is a pump with unlimited water. Given a positive integer c, how to get exactly c litres.
// Input
//    Line 1: contains positive integers a,   b,  c  (1 <= a, b, c <= 900)
// Output
//   write the number of steps or write -1 (if no solution found)
// Example

// Input
// 6  8  4
// Output
// 4
#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

bool isGoalState(int x, int y, int c) {
    return (x == c || y == c);
}

int waterJug(int a, int b, int c) {

    queue<pair<int, int>> Q;
    set<pair<int, int>> visited;

    Q.push({0, 0});
    visited.insert({0, 0});
    
    int steps = 0;

    while (!Q.empty()) {
        int size = Q.size();
        
        for (int i = 0; i < size; i++) {
            auto [x, y] = Q.front();
            Q.pop();

            if (isGoalState(x, y, c)) {
                return steps;
            }

            // Cac trang thai lan can
            // 1. Do day binh a
            if (visited.find({a, y}) == visited.end()) {
                Q.push({a, y});
                visited.insert({a, y});
            }
            // 2. Do day binh b
            if (visited.find({x, b}) == visited.end()) {
                Q.push({x, b});
                visited.insert({x, b});
            }
            // 3. Do het binh a
            if (visited.find({0, y}) == visited.end()) {
                Q.push({0, y});
                visited.insert({0, y});
            }
            // 4. Do het binh b
            if (visited.find({x, 0}) == visited.end()) {
                Q.push({x, 0});
                visited.insert({x, 0});
            }
            // 5. Do tu binh a sang binh b
            if (x + y <= b && visited.find({0, x + y}) == visited.end()) {
                Q.push({0, x + y});
                visited.insert({0, x + y});
            } else if (x + y > b && visited.find({x + y - b, b}) == visited.end()) {
                Q.push({x + y - b, b});
                visited.insert({x + y - b, b});
            }
            // 6. Do tu binh b sang binh a
            if (x + y <= a && visited.find({x + y, 0}) == visited.end()) {
                Q.push({x + y, 0});
                visited.insert({x + y, 0});
            } else if (x + y > a && visited.find({a, x + y - a}) == visited.end()) {
                Q.push({a, x + y - a});
                visited.insert({a, x + y - a});
            }
        }
        steps++;
    }

    return -1;
}

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << waterJug(a, b, c);
    return 0;
}
