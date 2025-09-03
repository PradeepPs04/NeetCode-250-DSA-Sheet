/*
    https://leetcode.com/problems/course-schedule-iv/description/

    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

        - For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
    Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

    You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

    Return a boolean array answer, where answer[j] is the answer to the jth query.

    Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
    Output: [false,true]
*/

class Solution {
private:
    bool path_exists(int node, int dest, vector<int>adj[], vector<int>& visited) {
        visited[node] = true;
        if(node == dest)    return true;

        for(auto it:adj[node]) {
            if(!visited[it]) {
                if(path_exists(it, dest, adj, visited)) return true;
            }
        }

        return false;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int>adj[101];
        for(auto it:prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<bool>ans;
        for(auto it:queries) {
            vector<int>visited(numCourses, 0);
            ans.push_back(path_exists(it[0], it[1], adj, visited));
        }

        return ans;
    }
};