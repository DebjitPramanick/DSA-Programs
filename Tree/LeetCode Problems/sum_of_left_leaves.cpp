// Sum of Left Leaves
// Time complexity -> O(n)

int sum = 0;

void solve(TreeNode *r, bool left = false)
{
    if (!r)
        return;
    if (!r->left && !r->right && left)
        sum += r->val;
    solve(r->left, true);
    solve(r->right, false);
    return;
}

int sumOfLeftLeaves(TreeNode *root)
{
    solve(root);
    return sum;
}