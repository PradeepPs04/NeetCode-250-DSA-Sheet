/*
    https://leetcode.com/problems/combination-sum-ii/description/

    Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

    Each number in candidates may only be used once in the combination.

    Note: The solution set must not contain duplicate combinations.

    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output: 
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
*/

class Solution {
public:
    void generate(vector<int>& candidates, int target, int idx,
                  vector<int> curr, vector<vector<int>>& ans) {
        // if target is achieved
        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        // for loop will ensure pick and not pick
        // for not pick we are popping last added element for the next
        // iterations

        // run a loop from idx to n
        for (int i = idx; i < candidates.size(); i++) {
            // check for duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // check for a valid number
            if (candidates[i] > target)
                break;

            // add element to current list
            curr.push_back(candidates[i]);
            // generate next subsets
            generate(candidates, target - candidates[i], i + 1, curr, ans);

            // remove last added element
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort given array
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;

        // generate all answers
        generate(candidates, target, 0, {}, ans);
        return ans;
    }
};