// Find Insertion Index of an element in a sorted array
// example: arr = [1,3,5,6], target = 5 -> output = 2
// example: arr = [1,3,5,6], target = 2 -> output = 1

//problem link: https://leetcode.com/problems/search-insert-position/   , byte: https://bytebytego.com/exercises/coding-patterns/binary-search/find-the-insertion-index

#include<bits/stdc++.h>
using namespace std;

int insertionInde(vector<int>& arr, int tar)
{
    int l = 0 ;
    int r = arr.size()-1;
    int mid =0;
    while(l<=r)
    {
        mid = l + (r-l)/2;
        if(mid == tar)
        {
            return mid;
        }
        else if(mid>tar)
        {
            r = mid-1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return l;
}