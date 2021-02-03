// Insertion in Binary Tree
// Deletion of node in a binary tree
// DFS (PreOrder, InOrder, PostOrder)
// BFS
// Find height of Binary Tree
// Count number of nodes

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *root, *newnode, *temp, *key_node;

void inorder(Node *temp)
{
    if (temp == NULL)
        return;

    inorder(temp->left);
    cout << temp->data << "\t";
    inorder(temp->right);
}

Node *createNode(int x)
{

    newnode = new Node();

    newnode->data = x;
    newnode->left = newnode->right = 0;

    return newnode;
}

Node *insertNode(int x)
{
    if (root == 0)
    {
        temp = createNode(x);
        return temp;
    }

    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->left != 0)
            q.push(temp->left);
        else
        {
            temp->left = createNode(x);
            return root;
        }

        if (temp->right != 0)
            q.push(temp->right);
        else
        {
            temp->right = createNode(x);
            return root;
        }
    }

    return root;
}


void searchNode(Node *root,int k){

    int found;

    if(!root) return;
    else{
        if(root->data == k) found = 1;
        else{
            searchNode(root->left, k);
            searchNode(root->right, k);
        }
    }

    if(found == 1) cout<<"Data found.";
}



int findHeight(Node *head)
{

    if (head == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = findHeight(head->left);
        int rheight = findHeight(head->right);

        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printLevel(Node *root, int level){
    if(root == 0) return;
    if(level == 1) cout<<root->data<<"\t";

    else{
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

void reverseLevelOrder(Node *root)
{
    int h = findHeight(root);
    int i;
    for (i = h; i >= 1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
        printLevel(root, i);
}



int main()
{

    root = 0;

    int s, ch;
    int exit = 0;

    root = createNode(5);
    root->left = createNode(6);
    root->left->left = createNode(1);
    root->right = createNode(9);
    root->right->left = createNode(11);
    root->right->right = createNode(18);

    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key;
    while (exit == 0)
    {
        cout << "\n1. Search in tree \n2. Reverse Level Order Traversal\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout<<"Enter data to search : ";
            cin>>s;
            searchNode(root,s);
            break;

        case 2:
            reverseLevelOrder(root);
            break;

        default:
            exit = 1;
        }
    }

    return 0;
}