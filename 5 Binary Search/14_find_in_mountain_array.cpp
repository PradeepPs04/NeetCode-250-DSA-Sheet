/*
    https://leetcode.com/problems/find-in-mountain-array/

    (This problem is an interactive problem.)

    You may recall that an array arr is a mountain array if and only if:

        - arr.length >= 3
        - There exists some i with 0 < i < arr.length - 1 such that:
            - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
            - Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

    You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

    MountainArray.get(k) returns the element of the array at index k (0-indexed).
    MountainArray.length() returns the length of the array.
    Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.


    Input: mountainArr = [1,2,3,4,5,3,1], target = 3
    Output: 2
*/

int findPeak(MountainArray &mountainArr)
{
    int low = 1;
    int high = mountainArr.length() - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int prev = mountainArr.get(mid - 1);
        int curr = mountainArr.get(mid);
        int next = mountainArr.get(mid + 1);

        // check for peak eleent
        if (curr > prev && curr > next)
            return mid;

        // eliminate one half
        if (prev < curr)
            low = mid + 1; // eliminate left half
        else
            high = mid - 1; // eliminate right half
    }

    return -1;
}

int binarySearch(MountainArray &mountainArr, int low, int high, int target, bool reverseBinarySearch)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int elem = mountainArr.get(mid);

        if (elem == target)
            return mid;

        // array after peak is reverse sorted
        if (reverseBinarySearch)
        {
            if (target > elem)
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (target > elem)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

int findInMountainArray(int target, MountainArray &mountainArr)
{
    // find peak element
    int peakIdx = findPeak(mountainArr);

    int idx = -1;

    // binary search on elements before peak
    bool reverseBinarySearch = false;
    idx = binarySearch(mountainArr, 0, peakIdx, target, reverseBinarySearch);

    cout << "length: " << mountainArr.length() << endl;
    cout << peakIdx << endl;

    if (idx != -1)
        return idx;

    // binary search on elements after peak
    reverseBinarySearch = true;
    return binarySearch(mountainArr, peakIdx + 1, mountainArr.length() - 1, target, reverseBinarySearch);
}