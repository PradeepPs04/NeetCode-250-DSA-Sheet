/*
    https://leetcode.com/problems/validate-binary-search-tree/description/

    Given the root of a binary tree, determine if it is a valid binary search tree (BST).

    A valid BST is defined as follows:

        - The left subtree of a node contains only nodes with keys strictly less than the node's key.
        - The right subtree of a node contains only nodes with keys strictly greater than the node's key.
        - Both the left and right subtrees must also be binary search trees.


    Input: root = [2,1,3]
    Output: true
*/

bool isValid(TreeNode *root, long mini, long maxi)
{
    if (!root)
        return true;

    // if invalid node return false
    if (root->val <= mini || root->val >= maxi)
        return false;

    // check for left values & right values
    return isValid(root->left, mini, root->val) && isValid(root->right, root->val, maxi);
}

bool isValidBST(TreeNode *root)
{
    // use long if maximum & minimum in tree nodes are equal to int_max & int_min
    return isValid(root, LONG_MIN, LONG_MAX);
}