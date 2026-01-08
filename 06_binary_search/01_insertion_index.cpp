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