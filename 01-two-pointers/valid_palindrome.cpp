// Problem Statement: Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
// Link: https://leetcode.com/problems/valid-palindrome/ , https://bytebytego.com/exercises/coding-patterns/two-pointers/is-palindrome-valid

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,s1;
    getline(cin,s);
    for(char c:s)
    {
        if(isalnum(c))
        {
            s1+=c;
        }
    }
    if(s1.length()==1)
    {
        cout<<"True"<<endl;
        return 0;
    }
    int left , right;
    left = 0;
    right = s1.length()-1;
    while(left<right)
    {

        if(s1[left]!=s1[right])
        {
            cout<<"False"<<endl;
            return 0;
        }
        left++;
        right--;
    }
    cout<<"True"<<endl;
    return 0;
}