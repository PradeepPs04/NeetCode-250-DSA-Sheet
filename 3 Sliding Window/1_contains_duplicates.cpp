/*
    https://leetcode.com/problems/contains-duplicate-ii/submissions/

    Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

    Input: nums = [1,2,3,1], k = 3
    Output: true

    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false
*/

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_set<int> st;
    int left = 0;
    int right = 0;
    while (right < nums.size())
    {
        // decrease window
        while (right - left > k)
            st.erase(nums[left++]);

        // check if element is present in window
        if (st.find(nums[right]) != st.end())
            return true;

        // increase window
        st.insert(nums[right++]);
    }

    return false;
}