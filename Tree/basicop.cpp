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
static int count = 0;

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

// Algorithm of deletion of a node

// 1. Starting at root, find the deepest and rightmost node in binary tree and node which we want to delete.
// 2. Replace the deepest rightmost node’s data with node to be deleted.
// 3. Then delete the deepest rightmost node.

void deleteDeepest(Node *node)
{
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

Node *deleteNode(int x)
{
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == x)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != 0)
    {
        int s = temp->data;
        deleteDeepest(temp);
        key_node->data = s;
    }

    return root;
}

int findHeight(Node *head){

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


int countNodes(Node *head){
    if(head == 0)
        return 0;

    countNodes(head->left);
    count++;
    countNodes(head->right);

    return count;
}

// DFS ------------------

void inOrderDisplay(Node *head)
{
    if (head != 0)
    {
        inOrderDisplay(head->left);
        cout << head->data << "\t";
        inOrderDisplay(head->right);
    }
}

void postOrderDisplay(Node *head)
{
    if (head != 0)
    {
        postOrderDisplay(head->left);
        postOrderDisplay(head->right);
        cout << head->data << "\t";
    }
}

void preOrderDisplay(Node *head)
{
    if (head != 0)
    {
        cout << head->data << "\t";
        preOrderDisplay(head->left);
        preOrderDisplay(head->right);
    }
}




// BFS ------------------


/* Print nodes at a given level */
void printGivenLevel(Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data <<"\t";
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}


void printLevelOrder(Node *root)
{
    int h = findHeight(root);
    int i;
    for (i = 1; i <= h; i++)
        printGivenLevel(root, i);
}





int main()
{

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
        cout << "\n1. Insert Node \n2. Delete Node\n3. Inorder display\n4. Preorder display\n5. Postorder display\n6. BFS Display\n7. Find Height of Tree\n8. Count Nodes\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the data : ";
            cin >> key;
            root = insertNode(key);
            inorder(root);
            break;

        case 2:
            cout << "Enter the data : ";
            cin >> key;
            root = deleteNode(key);
            inorder(root);
            break;

        case 3:
            inOrderDisplay(root);
            break;

        case 4:
            preOrderDisplay(root);
            break;

        case 5:
            postOrderDisplay(root);
            break;

        case 6:
            printLevelOrder(root);
            break;

        case 7:
            cout<<findHeight(root);
            break;

        case 8:
            cout << countNodes(root);
            break;

        default:
            exit = 1;
        }
    }

    return 0;
}
