/*
    https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

    A conveyor belt has packages that must be shipped from one port to another within days days.

    The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

    Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


    Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
    Output: 15
*/

bool canShip(vector<int> &weights, int capacity, int days)
{
    int curWeight = 0;
    int totalDays = 0;

    for (int w : weights)
    {
        curWeight += w;

        if (curWeight == capacity)
        {
            totalDays++;
            curWeight = 0;
        }
        else if (curWeight > capacity)
        {
            totalDays++;
            curWeight = w;
        }

        if (totalDays > days)
            return false;
    }

    if (curWeight > 0)
        totalDays++;

    return totalDays <= days;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int totalSum = 0;
    for (auto it : weights)
        totalSum += it;

    int low = *max_element(weights.begin(), weights.end());
    int high = totalSum;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canShip(weights, mid, days))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}