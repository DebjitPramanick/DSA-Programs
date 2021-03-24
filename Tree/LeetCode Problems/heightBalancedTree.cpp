// Balanced Binary Tree
// Time complexity -> O(n)

bool isBalan = true;
bool isBalanced(TreeNode *root)
{
    int temp = _isBalanced(root);
    return isBalan;
}
int _isBalanced(TreeNode *root)
{
    if (!root)
        return 0;
    int lH = _isBalanced(root->left);
    int rH = _isBalanced(root->right);
    if (abs(lH - rH) > 1)
        isBalan = false; //balanced check
    return 1 + max(lH, rH);
}