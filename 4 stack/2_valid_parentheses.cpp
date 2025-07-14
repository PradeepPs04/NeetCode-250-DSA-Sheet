/*
    https://leetcode.com/problems/valid-parentheses/

    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:
        1. Open brackets must be closed by the same type of brackets.
        2. Open brackets must be closed in the correct order.
        3. Every close bracket has a corresponding open bracket of the same type.


    Input: s = "([])"
    Output: true

    Input: s = "(]"
    Output: false
*/

bool isValid(string s)
{
    stack<char> st;

    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);
        else
        {
            if (st.empty())
                return false;
            else if (ch == ')' && st.top() != '(')
                return false;
            else if (ch == '}' && st.top() != '{')
                return false;
            else if (ch == ']' && st.top() != '[')
                return false;
            else
                st.pop();
        }
    }

    return st.empty();
}