/*
    http://leetcode.com/problems/binary-tree-right-side-view/description/

    Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.


    Input: root = [1,2,3,null,5,null,4]
    Output: [1,3,4]
*/

// iterative
vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return {};

    queue<TreeNode *> q;
    q.push(root);

    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->right)
                q.push(node->right);
            if (node->left)
                q.push(node->left);
        }
    }

    return ans;
}

// recursive
void dfs(TreeNode *root, vector<int> &ans, int level)
{
    if (!root)
        return;

    // if reaching the level for the first time
    if (level == ans.size())
        ans.push_back(root->val);

    // first go right
    dfs(root->right, ans, level + 1);
    // then go left
    dfs(root->left, ans, level + 1);
}

vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return {};

    vector<int> ans;

    dfs(root, ans, 0);

    return ans;
}