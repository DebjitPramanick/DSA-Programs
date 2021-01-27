#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head, *temp, *newnode, *nextnode, *cur;

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
        cout << temp->data << "        ";
        temp = temp->next;
    }
}

void deleteCons(){
    temp = head;
    cur = 0;
    int sum;

    while(temp->next!=NULL){
        sum = temp->data + temp->next->data;

        if(sum == 0){
            if(temp!=head){
                temp = temp->next->next;
                nextnode = cur->next;
                cur->next = temp;
                delete(nextnode);
                delete(nextnode->next);
            }
            else{
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


int main()
{
    head = NULL;

    int n, x, ch;
    int exit = 0;

    n = 0;

    cout << "Create nodes\n";

    while (n < 6)
    {
        cin >> x;
        createNode(x);
        n = n + 1;
    }

    displayList();

    cout << "\nChoose : ";

    while (exit == 0)
    {
        cout << "\n1. Delete consecutive elements with sum 0 \n2. Merge Two LL\n3. Flattening a linked list\n4. Add 1 to a number represented as a linked list\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            deleteCons();
            break;

        case 2:
            //findMiddle();
            break;

        case 3:
            //search();
            break;

        case 4:
            //deleteDup();
            break;

        default:
            exit = 1;
        }
    }
}