#include<bits/stdc++.h>
using namespace std;

string unique(string s)
{
    string res;
    stack<char>st;
    for(int i=0; i<s.size(); i++)
    {
        if(!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    cout<<res<<endl;

    return res;
}


int main()
{
    string s = "abbaca";
    string res;
    res = unique(s);
    return 0;
}
