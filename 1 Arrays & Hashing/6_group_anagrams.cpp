/*
    https://leetcode.com/problems/group-anagrams/

    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mpp;

    for (auto it : strs)
    {
        string s = it;
        sort(s.begin(), s.end());

        mpp[s].push_back(it);
    }

    vector<vector<string>> ans;

    for (auto it : mpp)
        ans.push_back(it.second);

    return ans;
}