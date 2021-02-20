// Maximum Depth of Binary Tree
// Time complexity - O(n)
// Recursive method

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    return max((1 + maxDepth(root->left)), (1 + maxDepth(root->right)));
}