// Path Sum

// Time complexity will be O(n)
// Find time complexity using reccursion tree method

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;

    targetSum = targetSum - root->val;

    if (!root->left && !root->right && targetSum == 0)
        return true;

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}