/*
    https://leetcode.com/problems/merge-k-sorted-lists/description/

    You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

    Merge all the linked-lists into one sorted linked-list and return it.


    Input: lists = [[1,4,5],[1,3,4],[2,6]]
    Output: [1,1,2,3,4,4,5,6]
*/

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return nullptr;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : lists)
    {
        ListNode *itr = i;
        while (itr)
        {
            pq.push(itr->val);
            itr = itr->next;
        }
    }

    ListNode *dummy = new ListNode(-1);
    ListNode *itr = dummy;
    while (!pq.empty())
    {
        ListNode *node = new ListNode(pq.top());
        pq.pop();
        itr->next = node;
        itr = itr->next;
    }

    itr = dummy->next;
    delete dummy;
    return itr;
}