//This is a brute force approach to find median of a stream of integers
//optimize it using two heaps in next code

#include<bits/stdc++.h>
using namespace std;

class MedianFinder{

    public:
    vector<int>res;
    void add(int x)
    {
        res.push_back(x);
    }
    float median()
    {
        int n = res.size();
        float mide;
        sort(res.begin(), res.end());
        if(res.size()%2==0)
        {
             mide =  (res[(n/2)-1]+res[n/2])/2.0;
        }
        else 
        {
            mide = (res[n/2])/1.0;
        }
        return mide;
    }
};