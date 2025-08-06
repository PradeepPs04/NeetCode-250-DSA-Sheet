/*
    https://leetcode.com/problems/house-robber-iii/description/

    The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

    Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

    Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.


    Input: root = [3,2,3,null,3,null,1]
    Output: 7
*/

int solve(TreeNode *root, unordered_map<TreeNode *, int> &dp)
{
    // no house to rob
    if (!root)
        return 0;

    // if already calculated for current node
    if (dp.find(root) != dp.end())
        return dp[root];

    // rob current house
    int rob_val = root->val;

    // skip left house and recurr for houses after taht
    if (root->left)
    {
        rob_val += solve(root->left->left, dp) + solve(root->left->right, dp);
    }

    // skip right house and recurr for houses after that
    if (root->right)
    {
        rob_val += solve(root->right->left, dp) + solve(root->right->right, dp);
    }

    // if current house is not robbed
    int not_rob_val = solve(root->left, dp) + solve(root->right, dp);

    // return maximum value
    return dp[root] = max(rob_val, not_rob_val);
}

int rob(TreeNode *root)
{
    unordered_map<TreeNode *, int> dp;
    return solve(root, dp);
}