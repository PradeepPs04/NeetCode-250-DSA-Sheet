/*
    https://leetcode.com/problems/reorder-list/description/

    You are given the head of a singly linked-list. The list can be represented as:
        L0 → L1 → … → Ln - 1 → Ln

    Reorder the list to be on the following form:
        L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

    You may not modify the values in the list's nodes. Only nodes themselves may be changed.

    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]
*/

void reorderList(ListNode *head)
{
    stack<ListNode *> st;

    ListNode *curr = head;
    while (curr)
    {
        st.push(curr);
        curr = curr->next;
    }

    curr = head;
    int k = st.size() / 2;
    while (k--)
    {
        ListNode *nextNode = curr->next;
        ListNode *lastCurr = st.top();

        curr->next = lastCurr;
        lastCurr->next = nextNode;

        curr = nextNode;
        st.pop();
    }

    curr->next = nullptr;
}