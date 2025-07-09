/*
    https://leetcode.com/problems/majority-element/

    Given an array nums of size n, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

    Input: nums = [3,2,3]
Output: 3
*/

int majorityElement(vector<int> &nums)
{
    int majority = 0;
    int vote = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        // if votes are 0 it means that this might be the possible candidate
        if (vote == 0)
        {
            majority = nums[i];
            vote = 1;
        }
        // if same vote increase it
        else if (nums[i] == majority)
            vote++;
        // if not same then eliminate 1 vote
        else
            vote--;
    }

    return majority;
}