/*
    https://leetcode.com/problems/container-with-most-water/description/

    You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

    Find two lines that together with the x-axis form a container, such that the container contains the most water.

    Return the maximum amount of water a container can store.

    Notice that you may not slant the container.

    
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49

*/

int maxArea(vector<int> &height)
{
    int left = 0;
    int right = height.size() - 1;

    int maxi = 0;
    while (left < right)
    {
        int distance = right - left;
        int water = distance * min(height[left], height[right]);
        maxi = max(maxi, water);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxi;
}