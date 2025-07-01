/*
    Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.
*/

void mergeArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    int gap = ceil((n + m) / 2.0);

    while (gap > 0)
    {
        int i = 0;
        int j = gap;

        while (j < n + m)
        {
            // if both pointers are in 1st array
            if (j < n && a[i] > a[j])
                swap(a[i], a[j]);
            // if i in 1st array and j in 2nd array
            else if (i < n && j >= n && a[i] > b[j - n])
                swap(a[i], b[j - n]);
            // if both pointers are in 2nd array
            else if (i >= n && b[i - n] > b[j - n])
                swap(b[i - n], b[j - n]);

            // increase pointers
            i++;
            j++;
        }

        // stop condition
        if (gap == 1)
            break;

        // update gap
        gap = ceil(gap / 2.0);
    }
}