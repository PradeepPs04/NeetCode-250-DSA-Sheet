/*
    https://leetcode.com/problems/course-schedule/

    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

        - For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
    Return true if you can finish all courses. Otherwise, return false.

    
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>indegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];

            adj[src].push_back(dest);
            indegree[dest]++;
        }

        int topo_size = 0;
        queue<int>q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)    q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo_size++;

            for(auto neighbour:adj[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)    q.push(neighbour);
            }
        }

        if(topo_size == numCourses)  return true;
        return false;
    }
};