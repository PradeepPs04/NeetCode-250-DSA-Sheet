/*
    https://leetcode.com/problems/rotate-array/description/

    Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

    Input: nums = [1,2,3,4,5,6,7], k = 3
    Output: [5,6,7,1,2,3,4]
*/

// approach-1
void rotate1(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> temp(n);

    // place element at it's rotated  in temporary array
    for (int i = 0; i < n; i++)
    {
        int position = (i + k) % n;
        temp[position] = nums[i];
    }

    // copy elements from temporary array
    for (int i = 0; i < n; i++)
        nums[i] = temp[i];
}

// appraoch-2
void rotate2(vector<int> &nums, int k)
{
    int n = nums.size();

    k = k % n;
    if (k == 0)
        return; // no rotation required

    vector<int> temp;

    // copy last k elements
    for (int i = nums.size() - k; i < n; i++)
        temp.push_back(nums[i]);
    // copy remaining elements from beginning
    for (int i = 0; i < nums.size() - k; i++)
        temp.push_back(nums[i]);

    // copy elements into original array
    for (int i = 0; i < n; i++)
        nums[i] = temp[i];
}

// approach-3
void rotate3(vector<int> &nums, int k)
{
    int n = nums.size();

    k = k % n;
    if (k == 0)
        return; // no rotation required

    reverse(nums.begin(), nums.end());       // reverse all elements
    reverse(nums.begin(), nums.begin() + k); // reverse first k elements
    reverse(nums.begin() + k, nums.end());   // reverse remaining elements (except first k)
}