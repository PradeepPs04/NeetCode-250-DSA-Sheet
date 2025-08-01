/*
    https://leetcode.com/problems/binary-tree-preorder-traversal/description/

    Given the root of a binary tree, return the preorder traversal of its nodes' values.


    Input: root = [1,null,2,3]
    Output: [1,2,3]
*/

// recursive
void preorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    preorder(root, ans);
    return ans;
}


// iterative
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *itr = root;

    while (itr || !st.empty())
    {
        if (itr)
        {
            st.push(itr);
            ans.push_back(itr->val);
            itr = itr->left;
        }
        else
        {
            itr = st.top();
            st.pop();
            itr = itr->right;
        }
    }

    return ans;
}


// Morris traversal
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode *itr = root;

    while (itr)
    {
        // if no left child
        if (!itr->left)
        {
            // print current
            ans.push_back(itr->val);
            // move right
            itr = itr->right;
        }
        else
        {
            // go to rightmost node of left child
            TreeNode *rightMost = itr->left;
            while (rightMost->right && rightMost->right != itr)
            {
                rightMost = rightMost->right;
            }

            // if no previous thread was created
            if (rightMost->right == nullptr)
            {
                // print current
                ans.push_back(itr->val);
                // create a thread
                rightMost->right = itr;
                // move left
                itr = itr->left;
            }
            else
            {
                // remove thread
                rightMost->right = nullptr;
                // move right
                itr = itr->right;
            }
        }
    }

    return ans;
}