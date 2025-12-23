// given an array move all the zeros to the end of the array
//link : https://bytebytego.com/exercises/coding-patterns/two-pointers/shift-zeros-to-the-end


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    int nextVal = 0;
    for(int i=0; i<n; i++)
    {
        if(nums[i]!=0)
        {
            nums[nextVal]=nums[i];
            nextVal++;
        }
    }
    for(int i=nextVal; i<n; i++)
    {
        nums[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}