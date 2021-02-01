// Insertion in Binary Tree
// Deletion of node in a binary tree

#include <iostream>
#include <queue>
using namespace std;

struct Node {
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

Node* createNode(int x){

    newnode = new Node();

    newnode->data = x;
    newnode->left = newnode->right = 0;

    return newnode;

}

Node *insertNode(int x)
{
    if(root == 0){
        temp = createNode(x);
        return temp;
    }

    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();


        if(temp->left != 0) q.push(temp->left);
        else {
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


// Algorithm of deletion of a node

// 1. Starting at root, find the deepest and rightmost node in binary tree and node which we want to delete. 
// 2. Replace the deepest rightmost node’s data with node to be deleted. 
// 3. Then delete the deepest rightmost node.

void deleteDeepest(Node* node){
    queue<struct Node *> q;
    q.push(root);

    // Do level order traversal until last node
    struct Node *temp;
    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp == node)
        {
            temp = NULL;
            delete (node);
            return;
        }
        if (temp->right)
        {
            if (temp->right == node)
            {
                temp->right = NULL;
                delete (node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left)
        {
            if (temp->left == node)
            {
                temp->left = NULL;
                delete (node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

Node* deleteNode(int x)
{
    queue<Node *> q;

    q.push(root);

    while(!q.empty()){
        temp = q.front();
        q.pop();

        if (temp->data == x) key_node = temp;

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    if(key_node != 0){
        int s = temp->data;
        deleteDeepest(temp);
        key_node->data = s;
    }

    return root;
}



int main(){

    root = 0;

    int n, x, ch;
    int exit = 0;

    root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);

    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;

    int key;
    while (exit == 0)
    {
        cout << "\n1. Insert Node \n2. Delete Node\n3. Delete n nodes after m nodes\n4. Detect loop\n5. Reverse in group\n6. Delete last occurence\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout<<"Enter the data : ";
            cin>>key;
            root = insertNode(key);
            inorder(root);
            break;

        case 2:
            cout << "Enter the data : ";
            cin >> key;
            root = deleteNode(key);
            inorder(root);
            break;

        default:
            exit = 1;
        }
    }

    return 0;
}
