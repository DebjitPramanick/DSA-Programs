#include <iostream>
using namespace std;

struct BST
{
    int data;
    BST *left;
    BST *right;
};

BST *root, *newnode, *temp, *key_node;

BST *root;

BST *createNode(int x)
{

    BST *newnode = new Node();

    newnode->data = x;
    newnode->left = newnode->right = 0;

    return newnode;
}

int main(){
    BST *root = 0;
    root = createNode(4);
}