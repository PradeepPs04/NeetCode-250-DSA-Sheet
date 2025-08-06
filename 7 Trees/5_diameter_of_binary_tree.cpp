/*
    https://leetcode.com/problems/diameter-of-binary-tree/description/

    Given the root of a binary tree, return the length of the diameter of the tree.

    The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

    The length of a path between two nodes is represented by the number of edges between them.


    Input: root = [1,2,3,4,5]
    Output: 3
*/

int diameter(TreeNode *root, int &ans)
{
    if (!root)
        return 0;

    // get answer from left sub-tree
    int left = diameter(root->left, ans);
    // get answer from right sub-tree
    int right = diameter(root->right, ans);

    // check for maximum
    ans = max(ans, left + right);

    // return the max distance from left or right
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int ans = 0;
    diameter(root, ans);

    return ans;
}