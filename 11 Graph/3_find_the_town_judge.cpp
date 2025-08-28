/*
    https://leetcode.com/problems/find-the-town-judge/description/

    In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

    If the town judge exists, then:
        1. The town judge trusts nobody.
        2. Everybody (except for the town judge) trusts the town judge.
        3. There is exactly one person that satisfies properties 1 and 2.
    You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

    Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

    Input: n = 2, trust = [[1,2]]
    Output: 2
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1, 0);
        vector<int>outdegree(n+1, 0);

        for(auto it:trust) {
            int u = it[0];
            int  v = it[1];

            indegree[v]++;
            outdegree[u]++;
        }


        for(int person = 1; person <= n; person++) {
            if(indegree[person] == n-1 && outdegree[person] == 0)   return person;
        }

        return -1;
    }
};