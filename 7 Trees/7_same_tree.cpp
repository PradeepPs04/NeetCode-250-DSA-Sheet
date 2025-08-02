/*
    https://leetcode.com/problems/same-tree/description/

    Given the roots of two binary trees p and q, write a function to check if they are the same or not.

    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


    Input: p = [1,2,3], q = [1,2,3]
    Output: true

    Input: p = [1,2], q = [1,null,2]
    Output: false
*/

bool isSameTree(TreeNode *p, TreeNode *q)
{
    // if any one is null, then second must be null
    if (!p)
        return q == nullptr;
    if (!q)
        return p == nullptr;

    // current node must be same && left subtree && right subtree must be same
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}