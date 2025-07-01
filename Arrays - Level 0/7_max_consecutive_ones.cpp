/*
    Given a binary array nums, return the maximum number of consecutive 1's in the array.

    Input: nums = [1,1,0,1,1,1]
    Output: 3
*/

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int cnt = 0;
    int maxi = 0;
    for (auto it : nums)
    {
        if (it == 1)
            cnt++;
        else
            cnt = 0;

        maxi = max(maxi, cnt);
    }

    return maxi;
}