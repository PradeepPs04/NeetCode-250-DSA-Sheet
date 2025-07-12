/*
    https://leetcode.com/problems/find-k-closest-elements/description/

    Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.

    An integer a is closer to x than an integer b if:

    |a - x| < |b - x|, or
    |a - x| == |b - x| and a < b


    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]

    Input: arr = [1,1,2,3,4,5], k = 4, x = -1
    Output: [1,1,2,3]
*/

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int left = 0;
    int right = arr.size() - 1;

    while (right - left + 1 > k)
    {
        // if left is more closer than right
        if (abs(arr[left] - x) <= abs(arr[right] - x))
            right--;
        // if right is more closer than left
        else
            left++;
    }

    // return array from left to right
    return vector<int>(arr.begin() + left, arr.begin() + right + 1);
}