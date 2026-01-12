#include<bits/stdc++.h>
using namespace std;


vector<int>NGE(vector<int>v)
{
    stack<int>st;
    vector<int>res(v.size(), -1);
    for(int i = 0; i<v.size(); i++)
    {
        while(!st.empty() && v[i]>res[st.top()])
        {
            res[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return res;
}