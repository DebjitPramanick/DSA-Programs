// Search in a Binary Search Tree
// Time complexity -. O(n)

TreeNode *searchBST(TreeNode *root, int val)
{
    if (!root)
        return NULL;
    if (val == root->val)
        return root;
    else
    {
        if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
}