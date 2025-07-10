/*
    https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

    Given a string s, find the length of the longest substring without duplicate characters.

    Input: s = "abcabcbb"
    Output: 3
*/

int lengthOfLongestSubstring(string s)
{
    // we can also use an array of size 255 instead of using hash map
    unordered_map<char, int> mpp;
    int left = 0, right = 0;
    int ans = 0;

    while (right < s.length())
    {
        // if there is a duplicate character
        // check if it's in current window
        // if yes => instead of moving left by 1 directly move to the position of repeating character
        // if no => it means repeating character is present but not in current window (it was previous somewhere) so our window is still valid (no need to shrink window)
        if (mpp.find(s[right]) != mpp.end())
            left = max(left, mpp[s[right]] + 1);
        mpp[s[right]] = right; // store the index of character in hash map

        // calculate the answer
        ans = max(ans, right - left + 1);

        // increase window size
        right++;
    }

    return ans;
}