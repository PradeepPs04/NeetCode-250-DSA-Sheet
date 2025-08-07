/*
    https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

    A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

    The path sum of a path is the sum of the node's values in the path.

    Given the root of a binary tree, return the maximum path sum of any non-empty path.

    Input: root = [1,2,3]
    Output: 6
*/

int getMaximum(TreeNode *root, int &ans)
{
    if (!root)
        return 0;

    int left = getMaximum(root->left, ans);
    int right = getMaximum(root->right, ans);

    // if left sub-tree is giving -ve, we can simply ignore that
    if (left < 0)
        left = 0;
    // if right sub-tree is giving -ve, we can simply ignore that
    if (right < 0)
        right = 0;

    // calcuate answer by taking left-path, right-path and current node
    ans = max(ans, left + right + root->val);

    // return the path that gives maximum value with current node
    return max(left, right) + root->val;
}

int maxPathSum(TreeNode *root)
{
    int ans = INT_MIN;
    getMaximum(root, ans);

    return ans;
}