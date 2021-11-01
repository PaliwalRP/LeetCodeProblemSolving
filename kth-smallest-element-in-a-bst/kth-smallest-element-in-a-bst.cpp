/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if (!root) return INT32_MIN; 
        auto fl = kthSmallest(root->left, k); 
        if (fl != INT32_MIN) return fl; 
        if (!(--k)) return root->val;  
        auto fr = kthSmallest(root->right, k); 
        if (fr != INT32_MIN) return fr; 
        
        return INT32_MIN;
    }
};