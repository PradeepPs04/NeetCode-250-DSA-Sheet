/*
    https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

    Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.


    Input: root = [3,1,4,null,2], k = 1
    Output: 1
*/

int inorder(TreeNode *root, int &k)
{
    if (!root)
        return -1;

    // search in left
    int left = inorder(root->left, k);
    // if element found in left part
    if (left != -1)
        return left;

    // decreament k
    k--;
    // check if Kth element is found
    if (k == 0)
        return root->val;

    // otherwise check on right part
    return inorder(root->right, k);
}
int kthSmallest(TreeNode *root, int k)
{
    // inorder traversal of a BST is sorted
    return inorder(root, k);
}