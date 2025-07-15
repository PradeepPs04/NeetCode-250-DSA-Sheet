/*
    https://leetcode.com/problems/generate-parentheses/description/

    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

void generate(int open, int close, string s, vector<string> &ans)
{
    if (open == 0 && close == 0)
    {
        ans.push_back(s);
        return;
    }

    if (open > 0)
        generate(open - 1, close, s + "(", ans);
    if (close > open)
        generate(open, close - 1, s + ")", ans);
}

vector<string> generateParenthesis(int n)
{
    vector<string> ans;
    generate(n, n, "", ans);

    return ans;
}