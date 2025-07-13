/*
    https://leetcode.com/problems/minimum-window-substring/

    Given two strings s and t, return the shortest substring of s such that every character in t, including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".

    You may assume that the correct output is always unique.


    Input: s = "OUZODYXAZV", t = "XYZ"
    Output: "YXAZ"

*/

string minWindow(string s, string t)
{
    int mpp[256] = {0};
    int req = 0;
    for (auto it : t)
    {
        if (mpp[it] == 0)
            req++;
        mpp[it]++;
    }

    int left = 0, right = 0;
    int mini = INT_MAX;
    int st = -1;

    while (right < s.length())
    {
        // add character to window
        mpp[s[right]]--;
        if (mpp[s[right]] == 0)
            req--;

        // check for valid window
        while (req == 0)
        {
            if (right - left + 1 < mini)
            {
                st = left;

                mini = right - left + 1;
            }

            mpp[s[left]]++;
            if (mpp[s[left]] == 1)
                req++;

            // decrease window
            left++;
        }

        // expand window
        right++;
    }

    if (st == -1)
        return "";

    return s.substr(st, mini);
}