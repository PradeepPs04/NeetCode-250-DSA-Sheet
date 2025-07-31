/*
    https://leetcode.com/problems/binary-tree-inorder-traversal/

    Given the root of a binary tree, return the inorder traversal of its nodes' values.


    Input: root = [1,null,2,3]
    Output: [1,3,2]
*/

// recursive
void inorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode *root)
{
    // declare array
    vector<int> ans;

    // do inorder traversal
    inorder(root, ans);

    // return answer
    return ans;
}

// iterative
vector<int> inorderTraversal(TreeNode *root)
{
    if (!root)
        return {};

    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *itr = root;

    while (itr || !st.empty())
    {
        if (itr)
        {
            st.push(itr);
            itr = itr->left;
        }
        else
        {
            itr = st.top();
            st.pop();

            ans.push_back(itr->val);
            itr = itr->right;
        }
    }

    return ans;
}

// morris traversal
vector<int> inorderTraversal(TreeNode *root)
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
            // go to right most node of left node
            TreeNode *rightMost = itr->left;
            while (rightMost->right && rightMost->right != itr)
            {
                rightMost = rightMost->right;
            }

            // if no previous thread was created
            if (!rightMost->right)
            {
                // create thread
                rightMost->right = itr;
                // move left
                itr = itr->left;
            }
            else
            {
                // remove thread
                rightMost->right = nullptr;
                // print current
                ans.push_back(itr->val);
                // move right
                itr = itr->right;
            }
        }
    }

    return ans;
}