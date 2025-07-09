/*
    https://leetcode.com/problems/boats-to-save-people/description/

    You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

    Return the minimum number of boats to carry every given person.


    Input: people = [1,2], limit = 3
    Output: 1
*/

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());

    int left = 0, right = people.size() - 1;
    int cnt = 0;

    while (left <= right)
    {
        if (people[left] + people[right] <= limit)
            left++;

        right--;
        cnt++;
    }

    return cnt;
}