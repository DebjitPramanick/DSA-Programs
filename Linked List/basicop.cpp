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

Node *head, *temp, *newnode, *nextnode;


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

}

void deleteDup(){

}

void search(){

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