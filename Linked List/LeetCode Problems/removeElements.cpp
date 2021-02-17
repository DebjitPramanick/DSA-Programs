// Remove simmilar elements from list (If there are 5 sixes, remove all sixes)

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *temp = new ListNode(-1);
    temp->next = head;
    head = temp;

    if (head == 0)
        return 0;

    while (temp != 0 && temp->next != 0)
    {
        if (temp->next->val == val)
        {
            temp->next = temp->next->next;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head->next;
}
}
;