// Symmetric Tree
// Time complexity -> O(n)


// Recursive approach

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return isMirror(root->left, root->right);
}

bool isMirror(TreeNode *r1, TreeNode *r2)
{
    if (!r1 && !r2)
        return true;
    else if (!r1 || !r2)
        return false;
    else
        return (r1->val == r2->val) &&
               isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
}


// Iterative approach

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    bool symmetric = true;
    TreeNode *temp1, *temp2;
    queue<TreeNode *> q1, q2;
    q1.push(root); //Transverse level From left to right
    q2.push(root); //Tranverse Level From Right to Left
    while (!q1.empty() && !q2.empty() && symmetric)
    {
        temp1 = q1.front();
        temp2 = q2.front();

        q1.pop();
        q2.pop();

        if (temp1 && temp2)
            symmetric = temp1->val == temp2->val;
        else
            symmetric = temp1 == temp2;

        if (temp1)
            if (temp1->left)
                q1.push(temp1->left);
            else
                q1.push(nullptr);
        if (temp1)
            if (temp1->right)
                q1.push(temp1->right);
            else
                q1.push(nullptr);
        if (temp2)
            if (temp2->right)
                q2.push(temp2->right);
            else
                q2.push(nullptr);
        if (temp2)
            if (temp2->left)
                q2.push(temp2->left);
            else
                q2.push(nullptr);
    }

    return (q1.empty() && q2.empty() && symmetric);
}