/*
    https://leetcode.com/problems/kth-largest-element-in-a-stream/description/

    You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

    You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

    Implement the KthLargest class:

        - KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
        - int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.


    Input:
        ["KthLargest", "add", "add", "add", "add", "add"]
        [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]

    Output: [null, 4, 5, 5, 8, 8]
*/

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
public:
    KthLargest(int k, vector<int>& nums) {
        int idx = 0;
        while(idx < nums.size() && k > 0)   {
            pq.push(nums[idx++]);
            k--;
        }

        // if k is less than array size
        while(idx < nums.size()) {
            if(nums[idx] > pq.top()) {
                pq.pop();
                pq.push(nums[idx]);
            }
            idx++;
        }

        // push dummy values
        while(k != 0) {
            pq.push(INT_MIN);
            k--;
        }
    }
    
    int add(int val) {
        if(val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};