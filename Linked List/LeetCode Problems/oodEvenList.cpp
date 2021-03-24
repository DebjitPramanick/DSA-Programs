// Odd Even Linked List (Odd/Even position not values)
// Time complexity - O(n)

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *temp1 = head, *temp2 = head->next;
    ListNode *temp = temp2;
    while (temp2 && temp2->next != nullptr)
    {
        temp1->next = temp1->next->next;
        temp1 = temp1->next;
        temp2->next = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = temp;
    return head;
}