/*
    https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

    Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

    According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”


    Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    Output: 6
*/

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // if root is null or any one node is a descendant of itself
    if (!root || root == p || root == q)
        return root;

    // if p & q both are on the left subtree
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

    // if p & q both are on the right subtree
    if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);

    // otherwise p & q are on the opposite subtree
    // one is on left and one is on right
    return root;
}