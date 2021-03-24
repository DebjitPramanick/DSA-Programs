// Create height balanced BST
// Time complexity -> O(n)

class Solution {
public:
    
    TreeNode* createBST(vector<int>&v, int l, int h){
        if(l>h) return NULL;
        int mid = l + (h-l)/2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = createBST(v, l, mid-1);
        node->right = createBST(v, mid+1, h);
        return node;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return createBST(nums, 0, n-1);
    }
};