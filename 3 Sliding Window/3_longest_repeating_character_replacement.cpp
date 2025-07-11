/*
    https://leetcode.com/problems/longest-repeating-character-replacement/description/

    You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

    Return the length of the longest substring containing the same letter you can get after performing the above operations.

    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

int characterReplacement(string s, int k)
{
    int left = 0, right = 0, maxFreq = 0;
    unordered_map<char, int> mpp;

    int ans = 0;
    while (right < s.length())
    {
        // add character to window
        mpp[s[right]]++;
        maxFreq = max(maxFreq, mpp[s[right]]);

        // shrink the window if condition is violated
        while (right - left + 1 - maxFreq > k)
        {
            mpp[s[left]]--;
            left++;
        }

        // update the answer if current window is larger
        ans = max(ans, right - left + 1);

        // increase the window
        right++;
    }

    return ans;
}