// Invert tree
// Time complexity - O(n)
// As we are visting all the nodes


// DFS Approach

TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return NULL;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);

    //Swap

    root->left = right;
    root->right = left;

    return root;
}

// BFS Approach

TreeNode *invertTree(TreeNode *root)
{
    if (!root)
        return NULL;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();
        TreeNode *temp = cur->left;
        cur->left = cur->right;
        cur->right = temp;

        if (cur->left)
            q.push(cur->left);
        if (cur->right)
            q.push(cur->right);
    }

    return root;
}