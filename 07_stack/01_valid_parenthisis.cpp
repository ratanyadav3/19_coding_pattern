
#include<bits/stdc++.h>
using namespace std;

bool valid_parenthesis(string s)
{
    unordered_map<char, int>bracket = {{'(', -3}, {'{', -2}, {'[', -1}, {']', 1}, {'}', 2}, {')', 3}};
    stack<char>st;
    for(int i =0 ; i<s.size(); i++)
    {
        if(bracket[s[i]]<0)
        {
            st.push(s[i]);
        }
        else 
        {
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if(bracket[s[i]]+bracket[top]!=0)
            {
                return false;
            }
            
        }
    }
    return st.empty();
}