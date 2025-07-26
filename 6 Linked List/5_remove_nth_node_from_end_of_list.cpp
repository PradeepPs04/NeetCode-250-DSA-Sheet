/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head;
    while (n--)
        fast = fast->next;

    // delete head
    if (!fast)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode *slow = head;
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode *temp = slow->next;
    slow->next = temp->next;
    delete temp;

    return head;
}