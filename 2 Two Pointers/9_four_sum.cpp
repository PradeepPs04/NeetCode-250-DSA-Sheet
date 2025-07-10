/*
    https://leetcode.com/problems/4sum/

    Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

       -> 0 <= a, b, c, d < n
       -> a, b, c, and d are distinct.
       -> nums[a] + nums[b] + nums[c] + nums[d] == target
    You may return the answer in any order.

    Input: nums = [1,0,-1,0,-2,2], target = 0
    Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++)
    {
        // skip duplicates
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < nums.size(); j++)
        {
            // skip duplicates
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = nums.size() - 1;

            long long req = (long long)target - ((long long)nums[i] + (long long)nums[j]);

            while (left < right)
            {
                long long sum = (long long)nums[left] + (long long)nums[right];

                if (sum == req)
                {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;

                    // skip duplicates
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (right > left && nums[right] == nums[right + 1])
                        right--;
                }
                else if (sum > req)
                    right--;
                else
                    left++;
            }
        }
    }

    return ans;
}