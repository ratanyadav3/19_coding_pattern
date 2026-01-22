#include<bits/stdc++.h>
using namespace std;

int largeOverlap(vector<vector<int>>& intervals)
{
    vector<pair<int,int>> events;

    for(auto &i : intervals)
    {
        events.push_back({i[0], +1}); // start
        events.push_back({i[1], -1}); // end
    }

    // If same time, end should come before start
    sort(events.begin(), events.end(), [](auto &a, auto &b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });

    int active = 0;
    int maxOverlap = 0;

    for(auto &e : events)
    {
        active += e.second;
        maxOverlap = max(maxOverlap, active);
    }

    return maxOverlap;
}
