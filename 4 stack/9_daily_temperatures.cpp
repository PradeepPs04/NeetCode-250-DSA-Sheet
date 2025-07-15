/*
    https://leetcode.com/problems/daily-temperatures/description/

    Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]
*/

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;
    vector<int> NGE(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && temperatures[st.top()] <= temperatures[i])
            st.pop();
        if (st.empty())
            NGE[i] = 0;
        else
            NGE[i] = st.top() - i;

        st.push(i);
    }
    return NGE;
}
