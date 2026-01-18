#include<bits/stdc++.h>
using namespace std; 

class MedianFinder {
private:

    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {
    }

    void addNum(int num) {

        maxHeap.push(num);

        
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Function to find the current median
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }

        return maxHeap.top();
    }
};