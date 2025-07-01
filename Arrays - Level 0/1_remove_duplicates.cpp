/*
    Given a sorted array arr. Return the size of the modified array which contains only distinct elements.
    Note:
        1. Don't use set or HashMap to solve the problem.
        2. You must return the modified array size only where distinct elements are present and modify the original array such that all the distinct elements come at the beginning of the original array.
*/

int removeDuplicates(vector<int> &arr)
{
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    return i + 1;
}