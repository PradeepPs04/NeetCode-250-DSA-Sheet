/*
    https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

    Given the root of a binary tree, return its maximum depth.

    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


    Input: root = [3,9,20,null,null,15,7]
    Output: 3
*/

// recursive (DFS)
int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;

    // get left depth
    int left = maxDepth(root->left);

    // get right depth
    int right = maxDepth(root->right);

    // return max + 1
    return 1 + max(left, right);
}

// iterative (BFS/LOT)
int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    queue<TreeNode *> q;

    int depth = 0;
    q.push(root);

    // go level by level
    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        // increament depth by 1 in each level
        depth++;
    }

    return depth;
}