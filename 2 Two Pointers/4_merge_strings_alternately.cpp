/*
    https://leetcode.com/problems/merge-strings-alternately/

    You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

    Return the merged string.


    Input: word1 = "abc", word2 = "pqr"
    Output: "apbqcr"
*/

string mergeAlternately(string word1, string word2)
{
    string ans = "";
    int i = 0, j = 0;
    while (i < word1.length() && j < word2.length())
    {
        ans += word1[i++];
        ans += word2[j++];
    }

    while (i < word1.length())
        ans += word1[i++];
    while (j < word2.length())
        ans += word2[j++];

    return ans;
}