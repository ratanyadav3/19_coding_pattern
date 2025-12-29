//prpblem statement : Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//link: https://www.codingninjas.com/codestudio/problems/consecutive-number_8230761?challengeSlug=striver-sde-challenge , https://bytebytego.com/exercises/coding-patterns/hash-maps-and-sets/consecutive-numbers


#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    set<int> s(nums.begin(), nums.end());

    int maxLen = 1, count = 1;
    int prev = *s.begin();

    for(auto it = next(s.begin()); it != s.end(); it++) {  
        int val = *it;
        if(val == prev + 1) {
            count++;
        } else {
            count = 1;
        }
        maxLen = max(maxLen, count);
        prev = val;
    }

    cout << maxLen << endl;
    return 0;
}
