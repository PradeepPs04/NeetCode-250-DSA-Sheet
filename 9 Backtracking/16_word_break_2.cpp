/*
    https://leetcode.com/problems/word-break-ii/description/

    Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

    Note that the same word in the dictionary may be reused multiple times in the segmentation.

    Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
    Output: ["cats and dog","cat sand dog"]
*/

class Solution {
public:
    void solve(string& s, int idx, string curr, unordered_map<string, bool>& mpp, vector<string>& ans) {
        if(idx == s.length()) {
            // remove the extra space from end
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        string word = "";
        for(int i = idx; i < s.length(); i++) {
            word += s[i];
            if(mpp[word]) {
                solve(s, i+1, curr+word+" ", mpp, ans);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // push dictionary words into a map
        unordered_map<string, bool>mpp;

        for(string& s:wordDict) mpp[s] = true;

        vector<string>ans;

        solve(s, 0, "", mpp, ans);

        return ans;
    }
};