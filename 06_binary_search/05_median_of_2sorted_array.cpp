//This approach is not binary search but a simple merging technique to find median of 2 sorted array
// example: nums1 = [1,3], nums2 = [2] -> output = 2.0
// example: nums1 = [1,2], nums2 = [3,4] -> output = 2.5

//problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/ , https://bytebytego.com/exercises/coding-patterns/binary-search/find-the-median-from-two-sorted-arrays

#include<bits/stdc++.h>
using namespace std;

float median(vector<int>&nums1 , vector<int>&nums2)
{
    vector<int>merg;
    double mid =0;

    int l1 = 0;
    int l2 = 0;
    while(l1<nums1.size() && l2<nums2.size())
    {
        if(nums1[l1]<nums2[l2])
        {
            merg.push_back(nums1[l1]);
            l1++;
        }
        else
        {
            merg.push_back(nums2[l2]);
            l2++;
        }
    }
    if(l1<nums1.size())
    {
        for(l1; l1<nums1.size(); l1++)
        {
            merg.push_back(nums1[l1]);
        }
    }
    else
    {
        for(l2; l2<nums2.size();l2++)
        {
            merg.push_back(nums2[l2]);
        }
    }
    if(merg.size()%2 == 0)
    {
        int first = merg.size()/2;
        int second = merg.size()/2 -1;
        mid = (merg[first]+merg[second])/2.0;
        return mid;
    }
    else 
    {
        mid = merg[merg.size()/2];
        return mid;
    }


}