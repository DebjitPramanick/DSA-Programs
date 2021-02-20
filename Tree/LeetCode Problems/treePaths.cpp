// Binary Tree Paths
// Time complexity -> O(n)

vector<string> ans;

void DFS(TreeNode *r, string s = "")
{
    if (!r)
        return;
    s += (s.empty() ? "" : "->") + to_string(r->val);
    if (!r->right && !r->left)
        ans.push_back(s);
    DFS(r->left, s);
    DFS(r->right, s);
}

vector<string> binaryTreePaths(TreeNode *root)
{
    DFS(root);
    return ans;
}