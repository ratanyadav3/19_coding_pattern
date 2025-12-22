// problem: Given a sorted array of integers and a target sum, determine if there exists a pair of numbers in the array that adds up to the target sum.
//link:https://bytebytego.com/exercises/coding-patterns/two-pointers/pair-sum-sorted


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,target;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int>result;
    cin>>target;
    int left=0;
    int right=n-1;
    
    while(left<right)
    {
        int current_sum=arr[left]+arr[right];
        if(current_sum==target)
        {
            result.push_back(left);
            result.push_back(right);
            break;
        }
        else if(current_sum<target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    if(result.size()==2)
    {
        cout<<result[0]<<" "<<result[1]<<endl;
    }
    else
    {
        cout<<"No pair found"<<endl;
    }
    
}