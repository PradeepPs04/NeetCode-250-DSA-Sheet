/*
    https://leetcode.com/problems/invert-binary-tree/description/

    Given the root of a binary tree, invert the tree, and return its root.


    Input: root = [4,2,7,1,3,6,9]
    Output: [4,7,2,9,6,3,1]
*/

void invert(TreeNode *root)
{
    if (!root)
        return;

    // swap left & right subtrees
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    // do the same for left & right subtrees
    invert(root->left);
    invert(root->right);
}

TreeNode *invertTree(TreeNode *root)
{
    invert(root);
    return root;
}