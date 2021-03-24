// Rotate List to the right by k places.

ListNode *rotateRight(ListNode *head, int k)
{
    if (head == nullptr)
        return nullptr;

    ListNode *k_behind = head;
    ListNode *curr = head;

    int len = 0;

    while (--k >= 0)
    {
        curr = curr->next;
        ++len;

        // (2)
        if (curr == nullptr)
        {
            k = k % len;
            curr = head;
        }
    }

    if (curr == head)
        return head; // (3)

    while (curr->next != nullptr)
    {
        curr = curr->next;
        k_behind = k_behind->next;
    }

    // (4)
    ListNode *newhead = k_behind->next;
    k_behind->next = nullptr;
    curr->next = head;

    return newhead;
}