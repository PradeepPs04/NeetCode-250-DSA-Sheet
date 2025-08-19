/*
    https://leetcode.com/problems/palindrome-partitioning/description/

    Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

    
    Input: s = "aab"
    Output: [["a","a","b"],["aa","b"]]
*/

class Solution {
public:
    bool palindrome(string s, int left, int right) {
        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }

        return true;
    }

    void generate(string& s, int left, vector<string>curr, vector<vector<string>>& ans) {
        if(left == s.length()) {
            ans.push_back(curr);
            return;
        }

        for(int right = left; right < s.length(); right++) {
           if(palindrome(s, left, right)) {
            curr.push_back(s.substr(left, right-left+1));
            generate(s, right+1, curr, ans);
            curr.pop_back();
           }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        generate(s, 0, {}, ans);
        return ans;
    }
};