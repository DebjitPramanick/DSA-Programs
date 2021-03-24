// Sum of Root To Leaf Binary Numbers
// Time complexity -> O(n)

int ret = 0;
int sumRootToLeaf(TreeNode* root){
    if(!root) return 0;
    if(!root->left && !root->right) ret += root->val;
    if(root->left) root->left->val += root->val<<1;
    if(root->right) root->right->val += root->val<<1;
    sumRootToLeaf(root->left);
    sumRootToLeaf(root->right);
    return ret;
}