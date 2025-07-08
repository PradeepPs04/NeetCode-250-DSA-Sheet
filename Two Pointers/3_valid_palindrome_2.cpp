/*
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.


    Input: s = "aba"
    Output: true
*/

class Solution
{
public:
    bool palindrome(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
                return false;
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        int left = 0, right = s.length() - 1;

        while (left < right)
        {
            if (s[left] != s[right])
            {
                // check for palindrome either by
                // removing left character
                // or right character
                if (palindrome(s, left + 1, right) || palindrome(s, left, right - 1))
                    return true;
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};