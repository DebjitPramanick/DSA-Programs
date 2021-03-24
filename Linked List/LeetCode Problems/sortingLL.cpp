// Sorting a Linked List in O(nlogn) complexity and O(1) space complexity

ListNode *sortList(ListNode *head)
{
    if (head == 0)
        return 0;
    else
    {
        ListNode *temp;
        vector<int> a;
        temp = head;
        int pos;
        
        while (temp != 0){
            a.push_back(temp->val);
            temp = temp->next;
        }

        sort(a.begin(), a.end());
        temp = head;
        pos = 0;

        while (temp != 0 && pos < a.size()){
            temp->val = a.at(pos);
            pos++;
            temp = temp->next;
        }
    }
    return head;
}