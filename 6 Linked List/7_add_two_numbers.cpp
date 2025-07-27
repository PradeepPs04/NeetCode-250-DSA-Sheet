/*
    https://leetcode.com/problems/add-two-numbers/description/

    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.


    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
*/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *itr = dummy;

    int carry = 0;
    while (l1 || l2 || carry)
    {
        int sum = 0;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        if (carry)
        {
            sum += carry;
        }

        carry = sum / 10;
        sum %= 10;

        ListNode *temp = new ListNode(sum);
        itr->next = temp;
        itr = temp;
    }

    ListNode *ans = dummy->next;
    delete dummy;

    return ans;
}