/*
    https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/

    Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

    Return the number of good nodes in the binary tree.


    Input: root = [3,1,4,3,null,1,5]
    Output: 4
*/

int count(TreeNode *root, int maxi)
{
    if (!root)
        return 0;

    // get maximum value on the current path
    maxi = max(maxi, root->val);

    // calculate good nodes on left side
    int left = count(root->left, maxi);
    // calculate good nodes on right side
    int right = count(root->right, maxi);

    // current node is good node add + 1
    if (maxi == root->val)
        return 1 + left + right;
    return left + right;
}
int goodNodes(TreeNode *root)
{
    return count(root, INT_MIN);
}