// Given a 2D matrix in which each row is sorted and the first element of each row is greater than the last element of the previous row, write an efficient algorithm that searches for a target value in the matrix. The algorithm should return true if the target is found and false otherwise.
// example: mat = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3 -> output = true

//problem link: https://leetcode.com/problems/search-a-2d-matrix/ , https://bytebytego.com/exercises/coding-patterns/binary-search/matrix-search

#include<bits/stdc++.h>
using namespace std;

bool Msearch(vector<vector<int>>& mat, int tar)
{
    int n = mat.size();
    int m = mat[0].size();

    int row = -1;

    // Step 1: Find the correct row
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == tar)
            return true;

        if (mat[i][0] > tar)
        {
            row = i - 1;
            break;
        }
    }

    // If tar is greater than all first-column elements
    if (row == -1)
        row = n - 1;

    // Step 2: Binary search in that row
    int l = 0, r = m - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (mat[row][mid] == tar)
            return true;
        else if (mat[row][mid] < tar)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return false;
}
