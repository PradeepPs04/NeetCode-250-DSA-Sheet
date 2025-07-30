/*
https://leetcode.com/problems/reverse-nodes-in-k-group/description/

    Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

    k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

    You may not alter the values in the list's nodes, only nodes themselves may be changed.


    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]
*/

ListNode *getKthNode(ListNode *itr, int k)
{
    while (itr->next && k > 1)
    {
        itr = itr->next;
        k--;
    }

    // if insufficient nodes to reverse
    if (k > 1)
        return nullptr;

    return itr;
}

ListNode *reverseList(ListNode *head)
{
    ListNode *prev = nullptr;
    while (head)
    {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (!head || !head->next || k <= 1)
        return head;

    ListNode *itr = head;
    ListNode *prevNode = nullptr;

    while (itr)
    {
        // get Kth node
        ListNode *kthNode = getKthNode(itr, k);

        if (!kthNode)
        {
            if (prevNode)
                prevNode->next = itr;
            break;
        }

        // get the next node
        ListNode *nextNode = kthNode->next;

        // break the list to reverse
        kthNode->next = nullptr;
        kthNode = reverseList(itr);

        // check if reversing 1st group
        if (itr == head)
            head = kthNode;

        // link previous list to current reversed list
        if (prevNode)
            prevNode->next = kthNode;

        // update prev node
        prevNode = itr;

        // update itr
        itr = nextNode;
    }

    return head;
}