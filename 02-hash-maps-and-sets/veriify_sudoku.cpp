//problem statement: given a 9 x 9 sudoku board, determine if it is valid. Only the filled cells need to be validated according to the following rules:
//1. Each row must contain the digits 1-9 without repetition.
//2. Each column must contain the digits 1-9 without repetition.
//3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//Note: A Sudoku board (partially filled) could be valid but is not necessarily solvable.
//Only the filled cells need to be validated according to the mentioned rules.
// problem link: https://leetcode.com/problems/valid-sudoku/    https://bytebytego.com/exercises/coding-patterns/hash-maps-and-sets/verify-sudoku-board


#include<bits/stdc++.h>
using namespace std;
#define N 9
int main()
{
    int board[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>board[i][j];
        }
    }
    return 0;   
}
bool isValidSudoku(int board[N][N]) {
    vector<set<char>> rows(N), cols(N), boxes(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char num = board[i][j];
            if (num == '.' || num == '0') continue; // Skip empty cells
            // Check row
            if (rows[i].count(num)) return false;
            rows[i].insert(num);
            // Check column
            if (cols[j].count(num)) return false;
            cols[j].insert(num);                    
            // Check 3x3 box
            int boxIndex = (i / 3) * 3 + (j / 3);
            if (boxes[boxIndex].count(num)) return false;
            boxes[boxIndex].insert(num);
        }
    }
    return true;
}