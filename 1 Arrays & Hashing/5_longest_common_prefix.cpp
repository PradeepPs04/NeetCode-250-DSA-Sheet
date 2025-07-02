/*
    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".

    Input: strs = ["flower","flow","flight"]
    Output: "fl"
*/

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 1)
        return strs[0];

    sort(strs.begin(), strs.end());

    int i = 0, n = strs.size();
    while (i < strs[0].length() && i < strs[n - 1].length() && strs[0][i] == strs[n - 1][i])
        i++;

    return strs[0].substr(0, i);
}