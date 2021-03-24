// Insertion in Binary Tree
// Deletion of node in a binary tree
// DFS (PreOrder, InOrder, PostOrder)
// BFS
// Find height of Binary Tree
// Count number of nodes

#include <iostream>
#include <queue>
#include <map>
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

int searchNode(Node *head, int f)
{
    if (!head)
        return 0;
    if (head->data == f)
        return 1;
    else
    {
        if (searchNode(head->left, f))
            return 1;
        if (searchNode(head->right, f))
            return 1;
    }
    return 0;
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


Node *reverseTreePathUtil(Node *root, int data,
                          map<int, int> &temp, int level, int &nextpos)
{
    // return NULL if root NULL
    if (root == NULL)
        return NULL;

    // Final condition
    // if the node is found then
    if (data == root->data)
    {

        // store the value in it's level
        temp[level] = root->data;

        // change the root value with the current
        // next element of the map
        root->data = temp[nextpos];

        // increment in k for the next element
        nextpos++;
        return root;
    }

    // store the data in perticular level
    temp[level] = root->data;

    // We go to right only when left does not
    // contain given data. This way we make sure
    // that correct path node is stored in temp[]
    Node *left, *right;
    left = reverseTreePathUtil(root->left, data, temp,
                               level + 1, nextpos);
    if (left == NULL)
        right = reverseTreePathUtil(root->right, data,
                                    temp, level + 1, nextpos);

    // If current node is part of the path,
    // then do reversing.
    if (left || right)
    {
        root->data = temp[nextpos];
        nextpos++;
        return (left ? left : right);
    }

    // return NULL if not element found
    return NULL;
}

// Reverse Tree path
void reverseTreePath(Node *root, int data)
{
    // store per level data
    map<int, int> temp;

    // it is for replacing the data
    int nextpos = 0;

    // reverse tree path
    reverseTreePathUtil(root, data, temp, 0, nextpos);
}

int main()
{

    root = 0;

    int s, ch, found;
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
        cout << "\n1. Search in tree \n2. Reverse Level Order Traversal\n3. Reverse Path\n";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout<<"Enter data to search : ";
            cin>>s;
            found = searchNode(root, s);
            if (found)
                cout << "Data found.";
            else
                cout << "Data is not there.";
            break;

        case 2:
            reverseLevelOrder(root);
            break;

        case 3:
            cout << "Enter path endpoint : ";
            cin >> s;
            reverseTreePath(root,s);
            inorder(root);
            break;

        default:
            exit = 1;
        }
    }

    return 0;
}