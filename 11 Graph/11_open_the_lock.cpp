/*
    https://leetcode.com/problems/open-the-lock/description/

    You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

    The lock initially starts at '0000', a string representing the state of the 4 wheels.

    You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.

    Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

    Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
    Output: 6
*/

// using queue
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool>dead;
        for(auto it:deadends)   dead[it] = true;

        // if starting point is deadend
        if(dead["0000"])    return -1;

        queue<pair<int, string>>q; // {moves, sequence}
        q.push({0, "0000"});

        int ans = INT_MAX;

        unordered_map<string, bool>visited;
        while(!q.empty()) {
            int moves = q.front().first;
            string seq = q.front().second;
            q.pop();

            if(seq == target) {
                ans = min(ans, moves);
                continue;
            }

            for(int i = 0; i < 4; i++) {
                char curr = seq[i];
                char prev = curr == '0' ? '9' : curr-1;
                char next = curr == '9' ? '0' : curr+1;

                // move dialer backwards
                seq[i] = prev;
                if(!dead[seq] && !visited[seq]) {
                    q.push({moves + 1, seq});
                    visited[seq] = true;
                }
                
                // move dialer forward
                seq[i] = next;
                if(!dead[seq] && !visited[seq]) {
                    q.push({moves + 1, seq});
                    visited[seq] = true;
                }

                // restore sequence for next character
                seq[i] = curr;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

// using min heap
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, bool>dead;
        for(auto it:deadends)   dead[it] = true;

        // if starting point is deadend
        if(dead["0000"])    return -1;

        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>>pq; // {moves, sequence}
        pq.push({0, "0000"});

        int ans = INT_MAX;

        unordered_map<string, bool>visited;
        while(!pq.empty()) {
            int moves = pq.top().first;
            string seq = pq.top().second;
            pq.pop();

            if(seq == target) {
                return moves;
            }

            for(int i = 0; i < 4; i++) {
                char curr = seq[i];
                char prev = curr == '0' ? '9' : curr-1;
                char next = curr == '9' ? '0' : curr+1;

                // move dialer backwards
                seq[i] = prev;
                if(!dead[seq] && !visited[seq]) {
                    pq.push({moves + 1, seq});
                    visited[seq] = true;
                }
                
                // move dialer forward
                seq[i] = next;
                if(!dead[seq] && !visited[seq]) {
                    pq.push({moves + 1, seq});
                    visited[seq] = true;
                }

                // restore sequence for next character
                seq[i] = curr;
            }
        }

        return -1;
    }
};