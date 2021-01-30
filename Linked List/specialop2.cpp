
#include <iostream>
#include <stack>
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

bool isPalindrome(){
    temp = head;
    int com;

    stack<int> s;

    while(temp != 0){
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;

    while(temp != 0){
        com = s.top();

        s.pop();

        if(com != temp->data) return false;

        temp = temp->next;
    }

    return true;
}

void rotateList(int k){
    temp = head;
    int i = 0;

    pre = 0;

    while(i<k){
        i++;
        pre = temp;
        temp=temp->next;
    }

    cur = pre;

    while(cur->next != 0) cur = cur->next;

    cur->next = head;
    head = pre->next;
    pre->next = 0;

    displayList();
}


void deleteNodes(int m, int n){
    temp = head;
    int i = 0;
    pre = 0;

    while(i<m){
        i++;
        pre = temp;
        temp = temp->next;
    }

    i = 0;
    cur = temp;

    while(i<n){
        i++;
        temp=temp->next;
    }

    pre->next = temp;
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
        cout << "\n1. Check if list palindrome \n2. Rotate list\n3. Delete n nodes after m nodes\n4. Detect loop\n5. Reverse in group\n6. Delete last occurence";
        cin >> ch;

        switch (ch)
        {
        case 1:
            if(isPalindrome()) cout<<"Yes, list is palindrome.";
            else
                cout << "No, list is not palindrome.";
            break;

        case 2:
            rotateList(3);
            break;

        case 3:

            deleteNodes(2,3);
            break;

        case 4:
            //detectLoop();
            break;

        case 5:
            //deleteLastOccur();
            break;

        default:
            exit = 1;
        }
    }
}