/*
    https://leetcode.com/problems/construct-quad-tree/description/

    Given a n * n matrix grid of 0's and 1's only. We want to represent grid with a Quad-Tree.

    Return the root of the Quad-Tree representing grid.

    A Quad-Tree is a tree data structure in which each internal node has exactly four children. Besides, each node has two attributes:

        - val: True if the node represents a grid of 1's or False if the node represents a grid of 0's. Notice that you can assign the val to True or False when isLeaf is False, and both are accepted in the answer.
        - isLeaf: True if the node is a leaf node on the tree or False if the node has four children.
            class Node {
                public boolean val;
                public boolean isLeaf;
                public Node topLeft;
                public Node topRight;
                public Node bottomLeft;
                public Node bottomRight;
            }

    We can construct a Quad-Tree from a two-dimensional area using the following steps:

        1- If the current grid has the same value (i.e all 1's or all 0's) set isLeaf True and set val to the value of the grid and set the four children to Null and stop.
        2- If the current grid has different values, set isLeaf to False and set val to any value and divide the current grid into four sub-grids as shown in the photo.
        3- Recurse for each of the children with the proper sub-grid.

    If you want to know more about the Quad-Tree, you can refer to the wiki.


    Quad-Tree format:

    You don't need to read this section for solving the problem. This is only if you want to understand the output format here. The output represents the serialized format of a Quad-Tree using level order traversal, where null signifies a path terminator where no node exists below.

    It is very similar to the serialization of the binary tree. The only difference is that the node is represented as a list [isLeaf, val].

    If the value of isLeaf or val is True we represent it as 1 in the list [isLeaf, val] and if the value of isLeaf or val is False we represent it as 0.


    Input: grid = [[0,1],[1,0]]
    Output: [[0,1],[1,0],[1,1],[1,1],[1,0]]
*/

class Solution
{
public:
    int checkLeaf(vector<vector<int>> &grid, int a, int b, int c, int d)
    {
        int val = grid[a][b];

        for (int i = a; i <= c; i++)
        {
            for (int j = b; j <= d; j++)
            {
                if (grid[i][j] != val)
                    return -1;
            }
        }

        return val;
    }

    Node *construct(vector<vector<int>> &grid, int a, int b, int c, int d)
    {
        // check if all 0's/1's or not
        int isLeaf = checkLeaf(grid, a, b, c, d);
        if (isLeaf == 0 || isLeaf == 1)
            return new Node(isLeaf, true);

        int n = c - a + 1; // size of current grid
        int x = n / 2;     // size of next grid

        // create parent node with (not a leaf node)
        Node *root = new Node(false, false);
        // create 4 children and check for next grid
        root->topLeft = construct(grid, a, b, c - x, d - x);
        root->topRight = construct(grid, a, b + x, c - x, d);
        root->bottomLeft = construct(grid, a + x, b, c, d - x);
        root->bottomRight = construct(grid, a + x, b + x, c, d);

        return root;
    }
    Node *construct(vector<vector<int>> &grid)
    {
        int n = grid.size();
        return construct(grid, 0, 0, n - 1, n - 1);
    }
};