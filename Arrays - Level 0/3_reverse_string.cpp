/*
    Write a function that reverses a string. The input string is given as an array of characters s.

    You must do this by modifying the input array in-place with O(1) extra memory.
*/

void reverseString(vector<char> &s)
{
    int r = s.size() - 1;
    int l = 0;
    while (l < r)
    {
        swap(s[l], s[r]);
        l++;
        r--;
    }
}