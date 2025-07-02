/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    Input: s = "anagram", t = "nagaram"
    Output: true

    Input: s = "rat", t = "car"
    Output: false
*/

// solution 1 -> using sorting
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != t[i])
            return false;
    }
    return true;
}

// solution 2 -> using hashmap of size 26
bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;

    vector<int> mpp(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        mpp[s[i] - 'a']++;
        mpp[t[i] - 'a']--;
    }

    for (auto it : mpp)
    {
        if (it != 0)
            return false;
    }

    return true;
}