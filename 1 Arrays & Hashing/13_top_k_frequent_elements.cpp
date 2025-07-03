/*
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
*/

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mpp;
    for (auto it : nums)
        mpp[it]++;

    vector<vector<int>> bucket(nums.size() + 1);

    for (auto it : mpp)
    {
        int elem = it.first;
        int idx = it.second;

        bucket[idx].push_back(elem);
    }

    vector<int> ans;

    for (int i = nums.size(); i >= 1; i--)
    {
        for (auto it : bucket[i])
        {
            ans.push_back(it);
            k--;
            if (k == 0)
                return ans;
        }
    }

    return ans;
}