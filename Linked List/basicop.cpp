// Sort LinkedList
// Search node
// Find Middle Element of LinkedList
// Delete Duplicate Element
// Reverse Linked List


#include <iostream>
using namespace std;

//findMiddle

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

    if(head == NULL){
        head = temp = newnode;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
}


void displayList(){

    cout << "List is : \n";

    temp = head;

    while(temp != NULL){
        cout<<temp->data<<"        ";
        temp = temp->next;
    }
}


void sort(){
    int result;
    
    temp = head;

    while (temp->next != 0)
    {
        nextnode = temp->next;

        while (nextnode != 0)
        {
            if (temp->data > nextnode->data)
            {

                result = temp->data;
                temp->data = nextnode->data;
                nextnode->data = result;
            }

            nextnode = nextnode->next;
        }

        temp = temp->next;
    }

    displayList();
}


void findMiddle(){
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}


void deleteDup(){
    temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        cur = temp;

        while (cur->next != NULL)
        {
            if (temp->data == cur->next->data)
            {
                nextnode = cur->next;
                cur->next = cur->next->next;
                delete (nextnode);
            }
            else
                cur = cur->next;
        }
        temp = temp->next;
    }

    displayList();
}


void search(){
    int x, found;
    cout<<"Enter element to search : ";
    cin>>x;

    temp = head;

    while(temp!=0){
        if(temp->data == x){
            found = 1;
            break;
        }
        temp = temp->next;
    }

    if(found == 1) cout<<"Element found.";
    else cout<<"Element not found.";
}


int main()
{
    head = NULL;

    int n,x,ch;
    int exit = 0;

    n = 0;

    cout<<"Create nodes\n";

    while (n<6)
    {
        cin>>x;
        createNode(x);
        n = n+1;
    }

    displayList();

    cout<<"\nChoose : ";
    
    
    while(exit == 0){
        cout<<"\n1. Sort\n2. Find Middle\n3. Search\n4. Delete Duplicate\n";
        cin>>ch;

        switch(ch){
            case 1:
                sort();
                break;

            case 2:
                findMiddle();
                break;

            case 3:
                search();
                break;

            case 4:
                deleteDup();
                break;

            default: 
                exit = 1;
        }
        
    }
}