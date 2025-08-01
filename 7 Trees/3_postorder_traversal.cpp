/*
    https://leetcode.com/problems/binary-tree-postorder-traversal/

    Given the root of a binary tree, return the postorder traversal of its nodes' values.


    Input: root = [1,null,2,3]
    Output: [3,2,1]
*/

// recursive
void postorder(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    postorder(root, ans);
    return ans;
}

// iterative
vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *itr = root;

    while (itr || !st.empty())
    {
        if (itr)
        {
            // push current to stack
            st.push(itr);
            // move left
            itr = itr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            // if right node exists
            if (temp)
            {
                itr = temp;
            }
            else
            {
                // print current
                temp = st.top();
                ans.push_back(temp->val);
                st.pop();

                // print element and go back
                while (!st.empty() && st.top()->right == temp)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
        }
    }

    return ans;
}