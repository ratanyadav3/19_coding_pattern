

#include<bits/stdc++.h>
using namespace std;


//time complexity: O(n*k)
//space complexity: O(1)
vector<int> maxOfWindow(vector<int>nums,int k)
{
    vector<int>res;
    for(int i = 0; i<nums.size()-k; i++)
    {
        int maxi = *max_element(nums.begin()+i, nums.begin()+i+k-1);
        res.push_back(maxi);
    }
    return res;
}


//let me write an optimized approach using deque
//time complexity: O(n)
//space complexity: O(k)


vector<int>MaxOfwindow(vector<int>nums , int k)
{
    deque<int>dq;
    vector<int>res;
    for(int i = 0; i<nums.size(); i++)
    {
        if(!dq.empty() && dq.front() == i-k )
        dq.pop_front();

        while(!dq.empty() && nums[dq.back()]<nums[i])
        {
            dq.pop_back();
        }

        dq.push_back(i);

        if(i>=k-1)
        res.push_back(nums[dq.front()]);
    }
    return res;
}