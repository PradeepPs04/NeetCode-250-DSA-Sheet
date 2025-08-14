/*
https://leetcode.com/problems/find-median-from-data-stream/description/

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
    - For example, for arr = [2,3,4], the median is 3.
    - For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:
    - MedianFinder() initializes the MedianFinder object.
    - void addNum(int num) adds the integer num from the data stream to the data structure.
    - double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

    Input
        ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
        [[], [1], [2], [], [3], []]
    Output
        [null, null, null, 1.5, null, 2.0]
*/

class MedianFinder {
private:
    priority_queue<int>leftMax; // max heap for left half
    priority_queue<int, vector<int>, greater<int>>rightMin; // min heap for right half
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // if current element is greater than maximum element on left half
        if(!leftMax.empty() && num > leftMax.top()) rightMin.push(num);
        else leftMax.push(num);

        // left half can contain at most 1 element more than right half
        if(leftMax.size() > rightMin.size()+1) {
            rightMin.push(leftMax.top());
            leftMax.pop();
        }

        // right half can not contain elements more than left half
        if(rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        // if no elements
        if(leftMax.empty()) return 0;

        // if even size
        if(leftMax.size() == rightMin.size()) {
            return (leftMax.top() + rightMin.top()) / 2.0;
        }

        return leftMax.top();
    }
};