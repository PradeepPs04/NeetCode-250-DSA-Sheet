/*
    https://leetcode.com/problems/encode-and-decode-strings/

    Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

    Please implement encode and decode

    Input: ["we","say",":","yes"]
    Output: ["we","say",":","yes"]
*/

string encode(vector<string> &strs)
{
    string ans = "";
    for (auto it : strs)
    {
        ans += it;
        ans += ";";
    }

    return ans;
}

vector<string> decode(string s)
{
    vector<string> ans;
    int i = 0;
    while (i < s.length())
    {
        string temp = "";
        while (s[i] != ';')
            temp.push_back(s[i++]);
        i++;
        ans.push_back(temp);
    }

    return ans;
}