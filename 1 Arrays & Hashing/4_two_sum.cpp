/*
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.

    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

// if given array is not sorted
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {
        int req = target - nums[i];
        if (mpp[req])
            return {mpp[req] - 1, i};
        mpp[nums[i]] = i + 1;
    }

    return {-1, -1};
}

// if given array is sorted
vector<int> twoSum(vector<int> &nums, int target)
{
    int left = 0, right = nums.size()-1;

    while(left < right)
    {
        int sum = nums[left] + nums[right];
        if(sum == target)   return {left, right};
        if(sum > target)    right--;
        else    left++;
    }

    return {-1, -1};
}