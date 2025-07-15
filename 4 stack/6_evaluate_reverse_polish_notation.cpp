/*
    http://leetcode.com/problems/evaluate-reverse-polish-notation/description/

    You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

    Evaluate the expression. Return an integer that represents the value of the expression.

    Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.

    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9
*/

bool isOperator(string s)
{
    if (s == "+" || s == "-" || s == "*" || s == "/")
        return true;
    return false;
}

int evaluate(int a, int b, string op)
{
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    return a / b;
}

int evalRPN(vector<string> &tokens)
{
    stack<int> st;
    for (string &s : tokens)
    {
        if (isOperator(s))
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            int result = evaluate(b, a, s);
            st.push(result);
        }
        else
            st.push(stoi(s));
    }

    return st.top();
}