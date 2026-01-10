// Find Target in Rotated Sorted Array
//example: nums = [4,5,6,7,0,1,2], target = 0 -> output = 4

//problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/ , https://bytebytego.com/exercises/coding-patterns/binary-search/find-the-target-in-a-rotated-sorted-array

#include<bits/stdc++.h>
using namespace std;
int find(vector<int>& nums, int tar)
{
    int l = 0, r = nums.size() - 1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (nums[mid] == tar)
            return mid;

        // Left half sorted
        if (nums[l] <= nums[mid])
        {
            if (tar >= nums[l] && tar < nums[mid])
                r = mid - 1;
            else
                l = mid + 1;
        }
        // Right half sorted
        else
        {
            if (tar > nums[mid] && tar <= nums[r])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    return -1;
}
