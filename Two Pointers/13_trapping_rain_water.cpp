/*
    https://leetcode.com/problems/trapping-rain-water/description/

    Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
*/

int trap(vector<int> &height)
{
    // store the maximum previous and next heights
    int left_max_height = 0, right_max_height = 0;

    // initialize two pointers
    int left = 0, right = height.size() - 1;

    int ans = 0;
    while (left < right)
    {
        left_max_height = max(left_max_height, height[left]);
        right_max_height = max(right_max_height, height[right]);

        // if left max is smaller then right max then increament left
        // pointer
        if (left_max_height < right_max_height)
        {
            ans += (left_max_height - height[left]);
            left++;
        }
        else
        {
            ans += (right_max_height - height[right]);
            right--;
        }
    }

    return ans;
}