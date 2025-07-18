/*
    https://leetcode.com/problems/largest-rectangle-in-histogram/

    Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

    Input: heights = [2,1,5,6,2,3]
    Output: 10
*/

class Solution
{
private:
    void calculatePSE(vector<int> &pse, vector<int> &heights)
    {
        stack<int> st;

        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }
    }

    void calculateNSE(vector<int> &nse, vector<int> &heights)
    {
        stack<int> st;

        for (int i = heights.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty())
                nse[i] = heights.size();
            else
                nse[i] = st.top();

            st.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> pse(heights.size());
        vector<int> nse(heights.size());

        calculatePSE(pse, heights);
        calculateNSE(nse, heights);

        int maxi = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            int l = heights[i];
            int b = nse[i] - pse[i] - 1;
            int area = l * b;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};