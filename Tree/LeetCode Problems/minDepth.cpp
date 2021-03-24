// Minimum Depth of Binary Tree
// Time complexity -> O(n)

// Recursive solution

int minDepth(TreeNode *root)
{

    if (!root)
        return 0;
    if (!root->right)
        return minDepth(root->left) + 1;
    if (!root->left)
        return minDepth(root->right) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}

// BFS method

int minDepth(TreeNode *root)
{

    if (!root)
        return 0;
    queue<TreeNode *> q;
    TreeNode *temp;

    q.push(root);
    int depth = 1;
    q.push(nullptr);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        if (temp && !temp->left && !temp->right)
            return depth;

        if (!temp)
        {
            if (q.empty())
                return depth;
            q.push(nullptr);
            depth++;
            continue;
        }

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    return depth;
}