#include<bits/stdc++.h>
using namespace std;

int ksum(vector<int>arr , int k)
{
    unordered_map<int,int>prefixsum;
    int sum =0;
    int count =0;
    prefixsum[0]=1;
    for(auto x :arr)
    {
        sum += x;
        if(prefixsum.find(sum - k) != prefixsum.end())
        {
            count += prefixsum[sum - k];
        }
        prefixsum[sum]++;
    }
    return count;

}