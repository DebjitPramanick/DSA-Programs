// Leaf-Similar Trees
// My First Approach

vector<int> v1, v2;

void pushLeaf1(TreeNode *r)
{
    if (!r)
        return;
    if (!r->left && !r->right)
        v1.push_back(r->val);
    pushLeaf1(r->left);
    pushLeaf1(r->right);
}
void pushLeaf2(TreeNode *r)
{
    if (!r)
        return;
    if (!r->left && !r->right)
        v2.push_back(r->val);
    pushLeaf2(r->left);
    pushLeaf2(r->right);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    pushLeaf1(root1);
    pushLeaf2(root2);
    if (v1 == v2)
        return true;
    return false;
}





// My second approach

vector<int> v1, v2;

void inorder(TreeNode *root, vector<int> &v)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        v.push_back(root->val);
    inorder(root->left, v);
    inorder(root->right, v);
}

bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    inorder(root1, v1);
    inorder(root2, v2);
    if (v1 == v2)
        return true;
    return false;
}