// Input: head = [1,2,3,4]
// Output: [2,1,4,3]


ListNode *swapPairs(ListNode *head)
{
    ListNode *cur;
    int temp;

    if (head == 0)
        return 0;

    cur = head;

    while (cur != 0 && cur->next != 0)
    {
        temp = cur->val;
        cur->val = cur->next->val;
        cur->next->val = temp;
        cur = cur->next->next;
    }

    return head;
}