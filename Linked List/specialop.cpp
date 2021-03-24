// Delete consecutive elements with sum 0
// Find nth node from the end of linked list
// Detect loop in linked list
// Remove loop from list
// Reverse list in a group
// Delete last occurence of an item in a list

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head, *temp, *newnode, *nextnode, *cur, *pre, *last, *first;

void createNode(int d)
{

    newnode = new Node();
    newnode->data = d;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void displayList()
{

    cout << "List is : \n";

    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "\t\t";
        temp = temp->next;
    }
}

void displayWithNode(struct Node *start)
{

    cout << "List is : \n";

    temp = start;

    while (temp != NULL)
    {
        cout << temp->data << "\t\t";
        temp = temp->next;
    }
}

void deleteCons()
{
    temp = head;
    cur = 0;
    int sum;

    while (temp->next != NULL)
    {
        sum = temp->data + temp->next->data;

        if (sum == 0)
        {
            if (temp != head)
            {
                temp = temp->next->next;
                nextnode = cur->next;
                cur->next = temp;
                delete (nextnode);
                delete (nextnode->next);
            }
            else
            {
                nextnode = temp;
                temp = temp->next->next;
                head = temp;
                delete (nextnode);
                delete (nextnode->next);
            }
        }

        cur = temp;
        temp = temp->next;
    }

    displayList();
}

void findFromLast()
{
    temp = head;
    int c = 0, i;
    int t;

    cout << "Enter idex of node from last : ";
    cin >> i;

    while (temp != 0)
    {
        c++;
        temp = temp->next;
    }

    t = (c - i) + 1;

    c = 0;
    temp = head;
    cur = 0;
    while (c < t)
    {
        c++;
        cur = temp;
        temp = temp->next;
    }

    cout << cur->data;
}

void deleteMiddle()
{
    temp = head;
    cur = head;
    pre = 0;

    while (temp != NULL && temp->next != NULL)
    {
        pre = cur;
        temp = temp->next->next;
        cur = cur->next;
    }

    pre->next = cur->next;
    delete (cur);

    displayList();
}

void removeLoop(struct Node *r)
{

    struct Node *p1;
    struct Node *p2;

    p1 = head;

    while (1)
    {
        p2 = r;

        while (p2->next != r && p2->next != p1)
            p2 = p2->next;

        if (p2->next == p1)
            break;

        p1 = p1->next;
    }

    p2->next = NULL;
}

void detectLoop()
{

    // last = head;
    // first = head;

    // while (last != 0)
    // {
    //     last = last->next;
    // }

    // last->next = first->next->next->next;

    temp = head;
    cur = head;

    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next->next;
        cur = cur->next;

        if (cur == temp)
            removeLoop(cur);
    }

    displayList();
}

Node *reverseInGroup(Node *t, int k)
{
    Node *current = t;
    Node *next = NULL;
    Node *prev = NULL;
    int count = 0;

    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != NULL)
        t->next = reverseInGroup(next, k);

    /* prev is new head of the input list */
    return prev;
}

void deleteLastOccur()
{
    int x;
    cout << "Enter data : ";
    cin >> x;

    temp = head;

    while (temp != 0)
    {

        if (temp->data == x)
        {
            cur = temp;
        }

        else if (temp->next != 0 && temp->next->data == x)
        {
            pre = temp;
        }

        temp = temp->next;
    }

    //cout << cur->next->data <<endl;

    pre->next = cur->next;
    delete(cur);

    displayList();
}





int main()
{
    struct Node *NODE;

    head = NULL;
    int l;

    int n, x, ch;
    int exit = 0;

    n = 1;

    cout << "Create nodes\n";

    while (n < 8)
    {
        cin >> x;
        createNode(x);
        n = n + 1;
    }

    displayList();

    cout << "\nChoose : ";

    while (exit == 0)
    {
        cout << "\n1. Delete consecutive elements with sum 0 \n2. Find n node from last\n3. Delete middle\n4. Detect loop\n5. Reverse in group\n6. Delete last occurence";
        cin >> ch;

        switch (ch)
        {
        case 1:
            deleteCons();
            break;

        case 2:
            findFromLast();
            break;

        case 3:
            deleteMiddle();
            break;

        case 4:
            detectLoop();
            break;

        case 5:
            cout << "Enter length of group: ";
            cin >> l;
            NODE = reverseInGroup(head, l);
            displayWithNode(NODE);
            break;

        case 6:
            deleteLastOccur();
            break;

        default:
            exit = 1;
        }
    }
}