//problem: Given a string s and an integer k, find the length of the longest substring that can be transformed into a uniform substring (all characters the same) by replacing at most k characters.    
// problem link: https://leetcode.com/problems/longest-repeating-character-replacement/ , https://bytebytego.com/exercises/coding-patterns/sliding-window/longest-uniform-substring-after-replacements


#include <bits/stdc++.h>

int longestUniformSubstring(std::string s, int k) {
    int n = s.length();
    if (n == 0) return 0;

    
    std::unordered_map<char, int> charCounts;
    int left = 0;
    int maxFreq = 0;
    int maxLength = 0;

    for (int right = 0; right < n; ++right) {
        
        charCounts[s[right]]++;
        
        
        maxFreq = std::max(maxFreq, charCounts[s[right]]);

    
        if ((right - left + 1) - maxFreq > k) {
            charCounts[s[left]]--;
            left++;
        }

        maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
}
