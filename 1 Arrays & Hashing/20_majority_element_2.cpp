/*
    https://leetcode.com/problems/majority-element-ii

    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Input: nums = [3,2,3]
    Output: [3]

    Input: nums = [1]
    Output: [1]

    Input: nums = [1,2]
    Output: [1,2]
*/

vector<int> majorityElement(vector<int> &nums)
{
    int maj1 = INT_MAX;
    int maj2 = INT_MAX;
    int cnt1 = 0;
    int cnt2 = 0;

    for (auto vote : nums)
    {
        if (vote == maj1)
            cnt1++;
        else if (vote == maj2)
            cnt2++;
        else if (cnt1 == 0)
        {
            maj1 = vote;
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            maj2 = vote;
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // verify
    int freq1 = 0;
    int freq2 = 0;
    for (auto it : nums)
    {
        freq1 += (it == maj1);
        freq2 += (it == maj2);
    }

    vector<int> ans;
    if (freq1 > nums.size() / 3)
        ans.push_back(maj1);
    if (freq2 > nums.size() / 3)
        ans.push_back(maj2);

    return ans;
}