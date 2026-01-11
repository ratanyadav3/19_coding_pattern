#include <bits/stdc++.h>
using namespace std;

class WeightedRandomSelection {
private:
    vector<int> prefix;
    int totalSum;

public:
    WeightedRandomSelection(vector<int>& weights) {
        totalSum = 0;
        for (int w : weights) {
            totalSum += w;
            prefix.push_back(totalSum);
        }
    }

    int select() {
        int rnd = rand() % totalSum + 1;  // [1, totalSum]

        // Binary search for first prefix >= rnd
        int idx = lower_bound(prefix.begin(), prefix.end(), rnd) - prefix.begin();
        return idx;
    }
};
