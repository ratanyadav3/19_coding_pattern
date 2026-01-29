

#include<bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if(op=='+' || op=='-')
        return 1;
    if(op=='*' || op=='/')
        return 2;
    return 0;
}

string infixToPostfix(string infix)
{
    string postfix;
    stack<char>st;
    for(int i=0; i<infix.size(); i++)
    {
        char ch = infix[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'))
        {
            postfix+=ch;
        }
        else if(ch=='(')
        {
            st.push(ch);
        }
        else if(ch==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && precedence(st.top())>=precedence(ch))
            {
                postfix+=st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while(!st.empty())
    {
        postfix+=st.top();
        st.pop();
    }
    return postfix;
}

int postfixEvaluate(string postfix)
{
    stack<int>st;
    for(int i=0; i<postfix.size(); i++)
    {
        char ch = postfix[i];
        if(ch>='0' && ch<='9')
        {
            st.push(ch-'0');
        }
        else
        {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch(ch)
            {
                case '+': st.push(val1+val2); break;
                case '-': st.push(val1-val2); break;
                case '*': st.push(val1*val2); break;
                case '/': st.push(val1/val2); break;
            }
        }
    }
    return st.top();
}