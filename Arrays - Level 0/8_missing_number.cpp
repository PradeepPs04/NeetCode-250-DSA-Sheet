/*
    Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

    Input: nums = [3,0,1]
    Output: 2

    Input: nums = [0,1]
    Output: 2
*/

// using sum of n natural numbers formula
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int sum_all = (n * (n + 1)) / 2;
    int arr_sum = 0;
    for (auto it : nums)
        arr_sum += it;

    return sum_all - arr_sum;
}

// using xor operator
int missingNumber(vector<int> &nums)
{
    int xorr = 0;
    // xor of first n numbers
    for (int i = 0; i <= nums.size(); i++)
        xorr ^= i;

    // xor of array
    for (auto it : nums)
        xorr ^= it;

    return xorr;
}