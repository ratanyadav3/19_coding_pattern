#include<bits/stdc++.h>
using namespace std;

vector<int> countSet(int n)
{
    vector<int>res;
    int count =0;
    for(int i=0; i<=n; i++)
    {
        count = __builtin_popcount(i);
        res.push_back(count);
        cout<<count<<", ";
    }
    return res;
}

int main()
{
    int n; 
    cin>>n;
    vector<int>res(n+1);
    res = countSet(n);

    return 0;
}