/*
    https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

    Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.


    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]
*/

TreeNode *construct(int &idx, int start, int end, vector<int> &preorder, vector<int> &inorder, unordered_map<int, int> &indexMap)
{
    // if all nodes are constructed or no child
    if (idx == preorder.size() || start > end)
        return nullptr;

    // create root
    TreeNode *root = new TreeNode(preorder[idx]);

    // get index of current root element in inorder traversal
    int i = indexMap[preorder[idx]];
    idx++; // increament index of preorder traversal for next node

    // construct left sub-tree
    root->left = construct(idx, start, i - 1, preorder, inorder, indexMap);
    // construct right sub-tree
    root->right = construct(idx, i + 1, end, preorder, inorder, indexMap);

    // return root
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    // store index of all element of inorder in map
    unordered_map<int, int> indexMap;
    for (int i = 0; i < inorder.size(); i++)
        indexMap[inorder[i]] = i;

    int idx = 0;
    return construct(idx, 0, inorder.size() - 1, preorder, inorder, indexMap);
}