/*
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    Note that you must do this in-place without making a copy of the array.

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
*/

void moveZeroes(vector<int> &nums)
{
    // left will point to the index of element that is 0
    // right will point to the index of non zero element
    int left = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] != 0)
            swap(nums[left++], nums[right]);
    }
}