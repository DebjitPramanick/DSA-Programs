// Maximum Depth of N-ary Tree
// Time complexity -> O(n)

int maxDepth(Node *root)
{
    if (!root)
        return 0;
    int ans = 0;
    for (int i = 0; i < root->children.size(); ++i)
    {
        ans = max(ans, maxDepth(root->children[i]));
    }

    return ans + 1;
}