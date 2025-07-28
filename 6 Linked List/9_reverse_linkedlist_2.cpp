/*
    https://leetcode.com/problems/reverse-linked-list-ii/description/

    Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.


    Input: head = [1,2,3,4,5], left = 2, right = 4
    Output: [1,4,3,2,5]
*/

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *prevNode = nullptr;
    ListNode *itr = head;

    for (int i = 1; i < left; i++)
    {
        prevNode = itr;
        itr = itr->next;
    }

    ListNode *prev = nullptr;
    ListNode *curr = itr;

    for (int i = left; i <= right; i++)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // if reverse from start => head will change
    if (left == 1)
        head = prev;

    if (prevNode)
        prevNode->next = prev;
    itr->next = curr;

    return head;
}