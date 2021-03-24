// Subtree of Another Tree
// Time complexity -> O(n) Space complexity -> O(h)

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL || p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSubtree(TreeNode *s, TreeNode *t)
{
    if (s == NULL || t == NULL)
        return false;
    if (isSameTree(s, t))
        return true;

    return isSubtree(s->left, t) || isSubtree(s->right, t);
}