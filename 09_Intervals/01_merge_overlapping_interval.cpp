#include<bits/stdc++.h>
using namespace std;


vector<pair<int,int>> mergeIntervals(vector<pair<int , int>> &intervals)
{
    if(intervals.size() == 0) return {};

    // Sort the intervals based on the starting time
    sort(intervals.begin(), intervals.end());

    vector<pair<int,int>> merged;
    merged.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++) {
        // If the current interval overlaps with the last merged interval
        if(intervals[i].first <= merged.back().second) {
            // Merge the intervals by updating the end time
            merged.back().second = max(merged.back().second, intervals[i].second);
        } else {
            // No overlap, add the current interval to merged list
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}