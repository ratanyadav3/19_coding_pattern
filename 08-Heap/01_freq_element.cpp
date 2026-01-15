#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;
        for (auto &w : words)
            freq[w]++;

        // Min-heap
        priority_queue<pair<int, string>,
                       vector<pair<int, string>>,
                       comp> pq;

        for (auto &p : freq) {
            pq.push({p.second, p.first});
            if (pq.size() > k)
                pq.pop();
        }

        vector<string> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }

private:
    struct comp {
        bool operator()(const pair<int, string>& a,
                        const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;  // lex larger first in min-heap
            return a.first > b.first;        // smaller frequency first
        }
    };
};
