/*
    https://leetcode.com/problems/reverse-string/

    Write a function that reverses a string. The input string is given as an array of characters s.

    You must do this by modifying the input array in-place with O(1) extra memory.


    Input: s = ["h","e","l","l","o"]
    Output: ["o","l","l","e","h"]
*/

void reverseString(vector<char> &s)
{
    int right = s.size() - 1;
    for (int left = 0; left < right; left++)
        swap(s[left], s[right--]);
}s