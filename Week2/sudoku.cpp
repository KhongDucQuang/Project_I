/*
Description
Write a program to compute the number of sudoku solutions 
(fill the zero elements of a given partial sudoku table)
Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:
Numbers of each row are distinct
Numbers of each column are distinct
Numbers on each sub-square 3 x 3 are distinct
Input
Each line i (i = 1, 2, ..., 9) contains elements of the ith
row of the Sudoku table: elements are numbers from 0 to 9 
(value 0 means the empty cell of the table)
Output
Write the number of solutions found
*/
#include <iostream>
using namespace std;
const int N = 9;
int board[N][N];
int count = 0;

bool check(int row, int col, int num){
    for(int i = 0; i < N; i++){
        if(board[row][i] == num){
            return false;
        }
    }
    for(int i = 0; i < N; i++){
        if(board[i][col] == num){
            return false;
        }
    }
    
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[startRow + i][startCol + j] == num){
                return false;
            }
        }
    }
    return true;
}

void Try(int row, int col){
    if(row == N){
        count++;
        return;
    }
    
    if(col == N){
        Try(row+1, 0);
        return;
    }

    if(board[row][col] != 0){
        Try(row, col+1);
        return;
    }

    for(int num = 1; num <= 9; num++){
        if(check(row, col, num)){
            board[row][col] = num;
            Try(row, col+1);
            board[row][col] = 0;
        }
    }
}

int main(){
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    Try(0, 0);
    cout << count;
    return 0;

}
