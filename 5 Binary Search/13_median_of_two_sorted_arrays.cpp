/*
    https://leetcode.com/problems/median-of-two-sorted-arrays/description/

    Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

    The overall run time complexity should be O(log (m+n)).


    Input: nums1 = [1,3], nums2 = [2]
    Output: 2.00000

    Input: nums1 = [1,2], nums2 = [3,4]
    Output: 2.50000
*/

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    if (m > n)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0;
    int high = nums1.size();

    while (low <= high)
    {
        int Px = low + (high - low) / 2;
        int Py = (m + n + 1) / 2 - Px;

        // left half
        int x1 = Px == 0 ? INT_MIN : nums1[Px - 1];
        int x2 = Py == 0 ? INT_MIN : nums2[Py - 1];

        // right half
        int x3 = Px == m ? INT_MAX : nums1[Px];
        int x4 = Py == n ? INT_MAX : nums2[Py];

        // check if valid partition is found
        if (x1 <= x4 && x2 <= x3)
        {
            if ((m + n) % 2 == 0)
                return (max(x1, x2) + min(x3, x4)) / 2.0;
            else
                return max(x1, x2);
        }

        // eliminate condition
        if (x1 > x4)
            high = Px - 1;
        else
            low = Px + 1;
    }

    return -1;
}