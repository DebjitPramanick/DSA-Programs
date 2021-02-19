// Swapping Nodes in a Linked List
// Time complexity - O(n)

ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *r, *s1, *s2;

    if (!head)
        return 0;
    if (!head->next)
        return head;

    r = 0;
    s1 = s2 = head;

    int c = k - 1;
    while (s1 && c)
    {
        c--;
        s1 = s1->next;
    }

    r = s1;

    while (s1->next)
    {
        s2 = s2->next;
        s1 = s1->next;
    }

    s1 = r;

    int res = s1->val;
    s1->val = s2->val;
    s2->val = res;

    return head;
}