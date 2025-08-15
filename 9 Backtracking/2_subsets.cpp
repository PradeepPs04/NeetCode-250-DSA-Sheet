/*
    https://leetcode.com/problems/subsets/description/

    Given an integer array nums of unique elements, return all possible subsets (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

void solve(vector<int> &nums, int idx, vector<int> curr, vector<vector<int>> &ans)
{
    if (idx < 0)
    {
        ans.push_back(curr);
        return;
    }

    // not pick
    solve(nums, idx - 1, curr, ans);
    // pick
    curr.push_back(nums[idx]);
    solve(nums, idx - 1, curr, ans);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    solve(nums, nums.size() - 1, {}, ans);

    return ans;
}