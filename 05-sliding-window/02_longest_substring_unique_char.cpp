

#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s)
{
    int left =0;
    int max_l = 0;
    unordered_set<char>seen;
    for(int right =0 ; right<s.size(); right++)
    {
        while(seen.count(s[right]))
        {
            seen.erase(s[left]);
            left++;
        }
        seen.insert(s[right]);
        int size1 = seen.size();
        max_l = max(max_l, size1);
    }
    return max_l;

}