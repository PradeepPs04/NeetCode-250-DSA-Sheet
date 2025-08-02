/*
    https://leetcode.com/problems/subtree-of-another-tree/description/

    Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

    A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.


    Input: root = [3,4,5,1,2], subRoot = [4,1,2]
    Output: true
*/

bool isSameTree(TreeNode *p, TreeNode *q)
{
    // if any one of node is null
    // then second must be null as well
    if (!p || !q)
        return p == q;

    // current value && left subtree && right subtree must be same
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if (!root)
        return false;

    // if any root has same value as subRoot
    // then check for identital tree
    if (root->val == subRoot->val && isSameTree(root, subRoot))
        return true;

    // check for left & right subtree
    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}