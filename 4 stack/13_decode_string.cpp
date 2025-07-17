/*
    https://leetcode.com/problems/decode-string/description/

    Given an encoded string, return its decoded string.

    The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

    You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

    The test cases are generated so that the length of the output will never exceed 105.

    Input: s = "3[a]2[bc]"
    Output: "aaabcbc"

    Input: s = "3[a2[c]]"
    Output: "accaccacc"
*/

string decodeString(string s)
{
    stack<char> st;

    for (char ch : s)
    {
        if (ch == ']')
        {
            string temp = "";
            while (st.top() != '[')
            {
                temp = st.top() + temp;
                st.pop();
            }

            st.pop(); // pop '['

            string rep = "";
            while (!st.empty() && isdigit(st.top()))
            {
                rep = st.top() + rep;
                st.pop();
            }
            int n = stoi(rep);

            string str = "";
            while (n--)
                str += temp;

            for (auto it : str)
                st.push(it);
        }
        else
        {
            st.push(ch);
        }
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}