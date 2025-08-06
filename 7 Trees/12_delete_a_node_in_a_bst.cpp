/*
    https://leetcode.com/problems/delete-node-in-a-bst/description/

    Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

    Basically, the deletion can be divided into two stages:

    Search for a node to remove.
    If the node is found, delete the node.


    Input: root = [5,3,6,2,4,null,7], key = 3
    Output: [5,4,6,2,null,null,7]
*/

int getInorderSuccessor(TreeNode *root)
{
    root = root->right;
    while (root->left)
        root = root->left;
    return root->val;
}

TreeNode *deleteNode(TreeNode *root, int key)
{
    if (!root)
        return nullptr;

    // if key is greater than current node then go right
    if (key > root->val)
        root->right = deleteNode(root->right, key);
    // if key is smaller than current node then go left
    else if (key < root->val)
        root->left = deleteNode(root->left, key);
    // key is found delete that node
    else
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;
        else
        {
            int successor = getInorderSuccessor(root);
            deleteNode(root, successor);
            root->val = successor;
            return root;
        }
    }

    return root;
}