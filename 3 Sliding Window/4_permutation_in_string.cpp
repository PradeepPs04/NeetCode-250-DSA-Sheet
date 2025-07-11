/*
    https://leetcode.com/problems/permutation-in-string/description/

    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2.


    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true

    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false
*/

class Solution
{
public:
    bool same(vector<int> &mpp1, vector<int> &mpp2)
    {
        for (int i = 0; i < 26; i++)
        {
            if (mpp1[i] != mpp2[i])
                return false;
        }

        return true;
    }

    bool checkInclusion(string s1, string s2)
    {
        if (s2.length() < s1.length())
            return false;

        vector<int> mpp1(26, 0);
        vector<int> mpp2(26, 0);

        for (int i = 0; i < s1.length(); i++)
        {
            mpp1[s1[i] - 'a']++;
            mpp2[s2[i] - 'a']++;
        }

        if (same(mpp1, mpp2))
            return true;

        int left = 0, right = s1.length();
        while (right < s2.length())
        {
            mpp2[s2[left] - 'a']--;
            mpp2[s2[right] - 'a']++;
            if (same(mpp1, mpp2))
                return true;

            left++;
            right++;
        }

        return false;
    }
};