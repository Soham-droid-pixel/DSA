#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    // Max-heap to store the smaller half of numbers
    priority_queue<int> small; 
    // Min-heap to store the larger half of numbers
    priority_queue<int, vector<int>, greater<int>> large; 

public:
    MedianFinder() {
        // Constructor remains empty as heaps initialize themselves
    }
    
    void addNum(int num) {
        // 1. Always push to small (max-heap) first
        small.push(num);
        
        // 2. Balancing: Move the largest of small to large (min-heap)
        // This ensures all elements in 'small' are <= all elements in 'large'
        large.push(small.top());
        small.pop();
        
        // 3. Maintain size property: small.size() >= large.size()
        // If large becomes bigger, move one back to small
        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() > large.size()) {
            // Odd number of elements: small has the middle one
            return (double)small.top();
        } else {
            // Even number of elements: average of the two tops
            return (small.top() + large.top()) / 2.0;
        }
    }
};