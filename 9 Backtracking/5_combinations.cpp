/*
    https://leetcode.com/problems/combinations/description/

    Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

    You may return the answer in any order.


    Input: n = 4, k = 2
    Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
*/

class Solution {
public:
    void generate(int idx, int n, int k, vector<int>curr, vector<vector<int>>& ans) {
        // if subset of k size is formed
        if(k == 0) {
            ans.push_back(curr);
            return;
        }

        // run loop uptil n
        for(int i = idx; i <= n; i++) {
            // add to current
            curr.push_back(i);
            // generate next
            generate(i+1, n, k-1, curr, ans);
            // pop back last added
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        generate(1, n, k, {}, ans);
        return ans;
    }
};