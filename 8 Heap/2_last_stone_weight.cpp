/*
    https://leetcode.com/problems/last-stone-weight/

    You are given an array of integers stones where stones[i] is the weight of the ith stone.

    We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

        -n If x == y, both stones are destroyed, and
        -n If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

    At the end of the game, there is at most one stone left.

    Return the weight of the last remaining stone. If there are no stones left, return 0.


    Input: stones = [2,7,4,1,8,1]
    Output: 1
*/

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> pq(stones.begin(), stones.end());

    while (pq.size() > 1)
    {
        // get 2 stones having maximum weight
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();

        // if both having different weight
        if (x != y)
        {
            int diff = abs(x - y);
            pq.push(diff);
        }
    }

    // if all stones are destroyed
    if (pq.size() == 0)
        return 0;

    return pq.top();
}