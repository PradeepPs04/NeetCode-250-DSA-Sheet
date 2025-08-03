/*
    https://leetcode.com/problems/binary-tree-level-order-traversal/description/

    Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).


    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[9,20],[15,7]]
*/

// recursive
int getHeight(TreeNode *root)
{
    if (!root)
        return 0;

    return 1 + max(getHeight(root->left), getHeight(root->right));
}

void lot(TreeNode *root, vector<int> &arr, int level)
{
    if (!root)
        return;
    if (level == 0)
    {
        arr.push_back(root->val);
        return;
    }

    lot(root->left, arr, level - 1);
    lot(root->right, arr, level - 1);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    int height = getHeight(root);

    vector<vector<int>> ans;
    for (int i = 0; i < height; i++)
    {
        vector<int> arr;
        lot(root, arr, i);
        ans.push_back(arr);
    }

    return ans;
}

// iterative
vector<vector<int>> levelOrder(TreeNode *root)
{
    if (!root)
        return {};

    queue<TreeNode *> q;
    vector<vector<int>> ans;

    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();

            level.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        ans.push_back(level);
    }

    return ans;
}