/*
    https://leetcode.com/problems/verifying-an-alien-dictionary/description/

    In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

    Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

    
    Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
    Output: true
*/

class Solution {
public:
    bool check(string a, string b, vector<int>& mpp) {
        int i = 0;
        while(i < a.length() && i < b.length()) {
            int order_i = mpp[a[i]-'a'];
            int order_j = mpp[b[i]-'a'];

            // if second word is smaller
            if(order_i > order_j)   return false;

            // if first word is smaller
            if(order_i < order_j)   return true;

            i++;
        }

        // both are equal
        // now check if first word has remaining characters
        // if yes then it must come after second word
        if(i < a.length())    return false;

        return true;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>mpp(26);
        for(int i = 0; i < order.length(); i++) mpp[order[i]-'a'] = i;

        for(int i = 0; i < words.size()-1; i++) {
            if(!check(words[i], words[i+1], mpp))   return false;
        }

        return true;
    }
};