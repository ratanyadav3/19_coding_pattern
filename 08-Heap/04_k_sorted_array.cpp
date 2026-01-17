#include<bits/stdc++.h>
using namespace std; 

vector<int>mergeKsortedArray(vector<int>&arr , int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int>res;
    for(int i = 0; i<=k && i<arr.size(); i++)
    {
        minHeap.push(arr[i]);
    }
    for(int i = k+1; i<arr.size(); i++)
    {
        res.push_back(minHeap.top());
        minHeap.pop();
        minHeap.push(arr[i]);
    }

     while (!minHeap.empty()) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }

    return res;
}