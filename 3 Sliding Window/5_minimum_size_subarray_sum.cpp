/*
    https://leetcode.com/problems/minimum-size-subarray-sum/description/

    Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.


    Input: target = 7, nums = [2,3,1,2,4,3]
    Output: 2

    Input: target = 4, nums = [1,4,4]
    Output: 1

    Input: target = 11, nums = [1,1,1,1,1,1,1,1]
    Output: 0
*/

int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0, right = 0;
    int sum = 0;

    int ans = INT_MAX;
    while (right < nums.size())
    {   
        // add elment to window
        sum += nums[right];
        
        // check for valid window
        while (sum >= target)
        {   
            ans = min(ans, right - left + 1);
            sum -= nums[left];
            left++;
        }

        // increse window
        right++;
    }

    return ans == INT_MAX ? 0 : ans;
}