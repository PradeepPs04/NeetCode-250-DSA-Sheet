/*
    https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

    You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

    Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.


    Input: root = [4,2,7,1,3], val = 5
    Output: [4,2,7,1,3,5]
*/

// recursive
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    // if root doesn't exist, then return new node
    if (!root)
        return new TreeNode(val);

    // if root value is greater then value, it means our root value exist on left side
    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    // otherwise root value is lesser then value, it means our root value exist on right side
    else
        root->right = insertIntoBST(root->right, val);

    // returning original root node
    return root;
}

// iterative
TreeNode *insertIntoBST(TreeNode *root, int val)
{
    // create new node
    TreeNode *node = new TreeNode(val);

    // if no root
    if (!root)
        return node;

    TreeNode *itr = root;
    while (1)
    {
        // if the node to be inserted on the left
        if (val < itr->val)
        {
            // if no node on left then insert node on left
            if (!itr->left)
            {
                itr->left = node;
                break;
            }

            // otherwise go to left
            itr = itr->left;
        }
        else
        {
            // if no node on right then insert node on right
            if (!itr->right)
            {
                itr->right = node;
                break;
            }

            // otherwise go to right
            itr = itr->right;
        }
    }

    // return updated tree
    return root;
}