// Problem Statement: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Link: https://leetcode.com/problems/container-with-most-water/ , https://bytebytego.com/exercises/coding-patterns/two-pointers/largest-container

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>height(n);
    for(int i=0; i<n; i++)
    {
        cin>>height[i];
    }
    int max_area = 0;
    int left = 0;
    int right = n-1;
    while(left<right)
    {
        int area = min(height[left],height[right])*(right-left);
        max_area = max(area, max_area);

        if(height[left]>height[right])
        right--;
        else
        left++;
    }

    cout<<"Max area "<<max_area<<endl;

    return 0;
}