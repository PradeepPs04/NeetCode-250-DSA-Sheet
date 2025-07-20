/*
    https://leetcode.com/problems/koko-eating-bananas/description/

    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

    Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

    Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

    Return the minimum integer k such that she can eat all the bananas within h hours.

    Input: piles = [3,6,7,11], h = 8
    Output: 4
*/

bool canEat(vector<int> &piles, int speed, int h)
{
    long totalTime = 0;
    for (auto banana : piles)
    {
        if (banana % speed == 0)
            totalTime += banana / speed;
        else
            totalTime += banana / speed + 1;

        if (totalTime > h)
            return false;
    }

    return totalTime <= h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canEat(piles, mid, h))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}