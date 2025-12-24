//prolem statement: Given a string representing a sequence of characters, find the next lexicographical permutation of the sequence. If no such permutation exists (i.e., the sequence is the highest possible permutation), return the lowest possible permutation (sorted in ascending order).
//link : https://leetcode.com/problems/next-permutation/ , https://bytebytego.com/exercises/coding-patterns/two-pointers/next-lexicographical-sequence


#include <bits/stdc++.h>
using namespace std;

string next_lexicographical_sequence(string s) {
    int n = s.length();
    int i = n - 2;


    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }

    // Step 2: If such a character exists, find the next larger character
    if (i >= 0) {
        int j = n - 1;
        while (s[j] <= s[i]) {
            j--;
        }
        swap(s[i], s[j]);
    }

    // Step 3: Reverse the suffix
    reverse(s.begin() + i + 1, s.end());

    return s;
}
