/*
    https://leetcode.com/problems/search-a-2d-matrix/description/

    You are given an m x n integer matrix matrix with the following two properties:

        - Each row is sorted in non-decreasing order.
        - The first integer of each row is greater than the last integer of the previous row.

    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true

    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
    Output: false
*/

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
            return true;

        if (target > matrix[row][col])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}