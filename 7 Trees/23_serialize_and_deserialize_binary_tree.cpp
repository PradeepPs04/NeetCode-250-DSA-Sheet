/*
    https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

    Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

    Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

    Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

    Input: root = [1,2,3,null,null,4,5]
    Output: [1,2,3,null,null,4,5]
*/

class Codec
{
private:
    void serializeHelper(TreeNode *root, string &ans)
    {
        // handle adding null values to string
        if (!root)
        {
            ans += ",";
            return;
        }

        // add current node value to string
        ans += to_string(root->val);
        ans += ","; // separator

        // go to the left sub-tree
        serializeHelper(root->left, ans);
        // go to the right sub-tree
        serializeHelper(root->right, ans);
    }

    TreeNode *deserializeHelper(string &data, int &idx)
    {
        if (idx == data.length())
            return nullptr;

        // get curernt value
        string curr = "";
        while (data[idx] != ',')
            curr += data[idx++];

        idx++; // go to the next character after seperator

        // if no value means current node is null
        if (curr == "")
            return nullptr;

        // create node
        TreeNode *root = new TreeNode(stoi(curr));

        // create left sub-tree
        root->left = deserializeHelper(data, idx);
        // create right sub-tree
        root->right = deserializeHelper(data, idx);

        // return node
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans = "";
        serializeHelper(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int idx = 0;
        return deserializeHelper(data, idx);
    }
};