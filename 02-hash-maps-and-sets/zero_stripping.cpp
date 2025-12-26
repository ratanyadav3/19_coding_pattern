//problem statement: Given a 2D matrix, if an element is 0, set its entire row and column to 0. Use hashing to optimize the solution.
//link: https://www.codingninjas.com/codestudio/problems/zero-stripping_8230760?challengeSlug=striver-sde-challenge , https://bytebytego.com/exercises/coding-patterns/hash-maps-and-sets/zero-striping



#include <bits/stdc++.h>
using namespace std;

void zero_striping(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    unordered_set<int> zero_rows, zero_cols;

    // Identify rows and columns that need to be zeroed
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zero_rows.insert(i);
                zero_cols.insert(j);
            }
        }
    }

    // Set entire row to zero
    for (int row : zero_rows) {
        for (int j = 0; j < cols; j++) {
            matrix[row][j] = 0;
        }
    }

    // Set entire column to zero
    for (int col : zero_cols) {
        for (int i = 0; i < rows; i++) {
            matrix[i][col] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    zero_striping(matrix);

    // Print the updated matrix
    for (auto &row : matrix) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
