//problem statement: Given two strings s and p, find all the start indices of p's anagrams in s.
//problem link: https://leetcode.com/problems/find-all-anagrams-in-a-string/ , https://bytebytego.com/exercises/coding-patterns/sliding-window/find-all-anagrams-in-a-string

#include<bits/stdc++.h>
using namespace std;

vector<int> anagram(string s , string p)
{
    unordered_map<char,int>pp,w;
    if(p.size()>s.size())
    return{};

    for(int i = 0; i<p.size(); i++)
    {
        pp[p[i]]++;
        w[s[i]]++;
    }
    vector<int>res;
    if(pp==w)
    res.push_back(0);

    for(int i = p.size(); i<s.size(); i++)
    {
        char left = s[i - p.size()];
        w[left]--;
        if(w[left] == 0)
        w.erase(left);
        w[s[i]]++;
        if(pp == w)
        res.push_back(i-p.size()+1);
    }
    return res;
}   