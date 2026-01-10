// Find First and Last Position of Element in Sorted Array
// example: nums = [5,7,7,8,8,10], target = 8 -> output = [3,4]


//problem link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/ , https://bytebytego.com/exercises/coding-patterns/binary-search/first-and-last-occurrences-of-a-number

#include<bits/stdc++.h>
using namespace std;


    int findFirst(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, first = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                first = mid;
                r = mid - 1; // look for earlier occurrence
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return first;
    }

    int findLast(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, last = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                last = mid;
                l = mid + 1; // look for later occurrence
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }