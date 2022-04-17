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
    TreeNode *increasingBST(TreeNode *root) {
        if (!root)
            return nullptr;
        return increasingBST(root, nullptr);
    }

    TreeNode *increasingBST(TreeNode *root, TreeNode *right) {
        auto head = root->left ? increasingBST(root->left, root) : root;
        root->left = nullptr;
        root->right = root->right ? increasingBST(root->right, right) : right;
        return head;
    }
};