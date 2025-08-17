/*
    https://leetcode.com/problems/permutations-ii/description/
    Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.


    Input: nums = [1,1,2]
    Output:
        [[1,1,2],
        [1,2,1],
        [2,1,1]]
*/

// hashmap approach
class Solution {
public:
    void generate(vector<int>& nums, unordered_map<int, int>& mpp, vector<int>curr, vector<vector<int>>& ans) {
        // if permutation of n size is generated
        if(curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for(auto it:mpp) {
            int elem = it.first;
            int count = it.second;

            // pick number only if it's available to pick
            if(count == 0)  continue;

            // add current element to permutation
            curr.push_back(elem);
            // decrease count of element in map
            mpp[elem] = count-1;

            // generate permutations
            generate(nums, mpp, curr, ans);

            // remove last picked elem
            curr.pop_back();
            // increase count of element in map
            mpp[elem] = count;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // store frequency of each element
        unordered_map<int, int>mpp;
        for(auto it:nums)   mpp[it]++;

        vector<vector<int>>ans;
        // generate all permutations
        generate(nums, mpp, {}, ans);

        return ans;
    }
};


// swap approach
class Solution {
public:
    void generate(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int>st; // to store all elements that are used in current level

        // swap all elemetns after idx in place of idx to generate permutations
        for(int i = idx; i < nums.size(); i++) {
            // check if an element is already used to generate permutations in this level
            if(st.find(nums[i]) != st.end())    continue;

            // use current element at this level
            st.insert(nums[i]);

            swap(nums[idx], nums[i]);
            // generate permutations
            generate(nums, idx+1, ans);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        generate(nums, 0, ans);
        return ans;
    }
};