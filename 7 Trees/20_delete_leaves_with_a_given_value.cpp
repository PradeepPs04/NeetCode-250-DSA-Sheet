/*
    https://leetcode.com/problems/delete-leaves-with-a-given-value/description/

    Given a binary tree root and an integer target, delete all the leaf nodes with value target.

    Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).


    Input: root = [1,2,3,2,null,2,4], target = 2
    Output: [1,null,3,null,4]
*/

TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    // if no node
    if (!root)
        return nullptr;

    // check for left sub-tree
    root->left = removeLeafNodes(root->left, target);
    // check for right sub-tree
    root->right = removeLeafNodes(root->right, target);

    // if current node is leaf node & equal to target
    if (!root->left && !root->right && root->val == target)
        return nullptr;

    // return updated root
    return root;
}