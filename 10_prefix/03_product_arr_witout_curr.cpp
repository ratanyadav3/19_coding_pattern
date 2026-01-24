#include<bits/stdc++.h>
using namespace std;


vector<int> productArray(vector<int> arr){
    double prod = 1;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]==0)continue;

        prod *= arr[i];
    }
    vector<int>res;

    for(int i = 0; i<arr.size(); i++)
    {
        if(arr[i]==0)
        {
            res.push_back(prod);
        }
        else
        {
            res.push_back(prod/arr[i]);
        }
    }
    return res;
}