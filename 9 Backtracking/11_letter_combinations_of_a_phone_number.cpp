/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

class Solution {
public:
    void generate(string& digits, int idx, string curr, unordered_map<char, string>& mpp, vector<string>& ans) {
        // after pressing all digits
        if(idx == digits.length()) {
            ans.push_back(curr);
            return;
        }

        // get characters of the digit
        string chars = mpp[digits[idx]];
        for(int i = 0; i < chars.length(); i++) {
            // add character of current digit
            curr += chars[i];
            // generate combinations with next digits
            generate(digits, idx+1, curr, mpp, ans);
            // remove while backtracking
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        // if no keys are pressed
        if(digits.length() == 0)    return {};

        // create mapping of characters in all key
        unordered_map<char, string>mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        vector<string>ans;

        // generate all combinations
        generate(digits, 0, "", mpp, ans);

        return ans;
    }
};