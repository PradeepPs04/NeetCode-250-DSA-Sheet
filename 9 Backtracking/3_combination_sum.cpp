/*
https://leetcode.com/problems/combination-sum/description/

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
*/

void generate(vector<int> &candidates, int idx, int target, vector<int> curr, vector<vector<int>> &ans)
{
    if (idx < 0)
    {
        if (target == 0)
            ans.push_back(curr);
        return;
    }

    // not pick
    generate(candidates, idx - 1, target, curr, ans);

    // pick only if currentcandidate <= current target
    if (candidates[idx] <= target)
    {
        curr.push_back(candidates[idx]);
        generate(candidates, idx, target - candidates[idx], curr, ans);
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    generate(candidates, candidates.size() - 1, target, {}, ans);
    return ans;
}