/*
    Given an array of integers nums, sort the array in ascending order and return it.

    You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.


    Input: nums = [5,2,3,1]
    Output: [1,2,3,5]
*/

void merge(vector<int> &nums, int low, int mid, int high)
{
    int n1 = mid - low + 1; // size of left half
    int n2 = high - mid;    // size of right half

    vector<int> left(n1), right(n2);

    // copy left half
    int i = low;
    for (int j = 0; j < n1; j++)
        left[j] = nums[i++];

    // copy right half
    for (int j = 0; j < n2; j++)
        right[j] = nums[i++];

    // sorted copy into original array from left & right half
    int j = 0, k = 0;
    i = low;

    while (j < n1 && k < n2)
    {
        if (left[j] <= right[k])
            nums[i++] = left[j++];
        else
            nums[i++] = right[k++];
    }

    // copy reamining elements
    while (j < n1)
        nums[i++] = left[j++];
    while (k < n2)
        nums[i++] = right[k++];
}

void mergeSort(vector<int> &nums, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
}

vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);

    return nums;
}