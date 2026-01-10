//problem Statement: Given an array, find a local maxima in it. An array element is a local maxima if it is NOT smaller than its neighbors.
// example: arr = [1,3,20,4,1,0,5] -> output = 20 (index 2)
// example: arr = [10,20,15,2,23,90,67] -> output = 20 (index 1)

//link : https://www.geeksforgeeks.org/find-a-local-maxima-in-an-array/ , https://bytebytego.com/exercises/coding-patterns/binary-search/local-maxima-in-array
#include<bits/stdc++.h>
using namespace std;

int localMaxima(vector<int>&arr)
{
    int n = arr.size();
    if(arr[0]>arr[1])
    {
        return(0);
    }
    else if(arr[n-1]>arr[n-2])
    {
        return n-1;
    }

    for(int i = 1; i < n-1; i++)
    {
        if(arr[i]>arr[i-1 && arr[i]>arr[i+1]])
        return i;
    }
    return (-1);
}