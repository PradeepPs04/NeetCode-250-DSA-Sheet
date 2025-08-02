/*
    https://leetcode.com/problems/balanced-binary-tree/description/

    Given a binary tree, determine if it is height-balanced.


    Input: root = [3,9,20,null,null,15,7]
    Output: true
*/

int height(TreeNode *root)
{
    if (!root)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    // if any sub-tree is not height-balanced
    if (left == -1 || right == -1)
        return -1;

    // check if current sub-trees are height-balanced
    if (abs(left - right) > 1)
        return -1;

    // return depth of current sub-tree
    return 1 + max(left, right);
}
bool isBalanced(TreeNode *root)
{
    return height(root) != -1;
}