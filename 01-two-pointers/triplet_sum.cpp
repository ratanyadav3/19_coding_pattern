// Problem Statement: Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.
// Link: https://leetcode.com/problems/3sum/ , https://bytebytego.com/exercises/coding-patterns/two-pointers/triplet-sum


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i = 0; i<n; i++)
    {
        cin>>nums[i];
    }
    vector<vector<int>>result;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n-2; i++)
    {
        if(i>0 && nums[i]==nums[i-1]) continue; 
        int left = i+1;
        int right = n-1;
        while(left<right)
        {
            int sum = nums[i]+nums[left]+nums[right];
            if(sum==0)
            {
                result.push_back({nums[i],nums[left],nums[right]});

                while(left<right && nums[left]==nums[left+1])left++;
                while(left<right && nums[right]==nums[right-1])right--;

                left++;
                right--;
            }
            else if(sum<0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    for(auto triplet: result)
    {
        cout<<triplet[0]<<" "<<triplet[1]<<" "<<triplet[2]<<endl;
    }
    return 0;
}