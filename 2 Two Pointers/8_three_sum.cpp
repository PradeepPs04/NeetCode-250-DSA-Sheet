/*
    https://leetcode.com/problems/3sum/description/

    Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

    Notice that the solution set must not contain duplicate triplets.

    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        // skip duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int k = 0 - nums[i];
        // use Two sum for remaining
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right];
            if (sum == k)
            {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                
                // skip duplicates
                while (left < right && nums[left] == nums[left - 1])
                    left++;
                // skip duplicates
                while (left < right && nums[right] == nums[right + 1])
                    right--;
            }
            else if (sum < k)
                left++;
            else
                right--;
        }
    }

    return ans;
}