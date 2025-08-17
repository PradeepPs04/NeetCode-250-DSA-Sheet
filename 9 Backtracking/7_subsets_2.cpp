/*
    https://leetcode.com/problems/subsets-ii/

    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.


    Input: nums = [1,2,2]
    Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

class Solution {
public:
    void generate(vector<int>& nums, int idx, vector<int> curr, vector<vector<int>>& ans) {
        // run a loop from idx to n
        for(int i = idx; i < nums.size(); i++) {
            // skip generating duplicate subsets
            if(i > idx && nums[i] == nums[i-1]) continue;

            // add current number
            curr.push_back(nums[i]);
            // generate next subsets
            generate(nums, i+1, curr, ans);
            // remove last added number for next permutations
            curr.pop_back();
        }

        // add current subset to answer
        ans.push_back(curr);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort the given array
        sort(nums.begin(), nums.end());

        vector<vector<int>>ans; // to store answer
        // generate all subsets
        generate(nums, 0, {}, ans);

        return ans;
    }
};