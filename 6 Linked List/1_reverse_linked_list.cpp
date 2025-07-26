/*
    https://leetcode.com/problems/reverse-linked-list/

    Given the head of a singly linked list, reverse the list, and return the reversed list.

    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]
*/

// interative solution
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next = head;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// recursive solution
ListNode *reverseList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *newHead = reverseList(head->next);

    ListNode *nextNode = head->next;
    nextNode->next = head;
    head->next = nullptr;

    return newHead;
}
