/*
    Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

    Each product is guaranteed to fit in a 32-bit integer.

    Input: nums = [1,2,4,6]
    Output: [48,24,12,8]


    Follow-up: Could you solve it in O(n) time without using the division operation?
*/

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    // compute prefix product
    vector<int> prefix(n);
    prefix[0] = 1;
    for (int i = 1; i < n; i++)
        prefix[i] = nums[i - 1] * prefix[i - 1];

    // compute suffix product
    vector<int> suffix(n);
    suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        suffix[i] = nums[i + 1] * suffix[i + 1];

    vector<int> ans;
    for (int i = 0; i < n; i++)
        ans.push_back(prefix[i] * suffix[i]);

    return ans;
}