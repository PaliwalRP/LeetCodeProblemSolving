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
    TreeNode* deleteNode(TreeNode* root, int key) {
        auto c = root;
		//boundary guard
        TreeNode* p = root = new TreeNode(100001, root, NULL);
        while(c != NULL)
        {
            if (c->val == key)
            {
                bool left = c == p->left;
                if (c->right == NULL)
                {
                    if (left) p->left = c->left;
                    else p->right = c->left;  
                    delete c;
                }
                else
                {
                    auto tmp = c;
                    c = c->right;
                    //find min in right tree
                    while(c->left != NULL)
                    {
                        tmp = c;
                        c = c->left;
                    }
                    if (tmp->left == c) tmp->left = c->right;
                    else tmp->right = c->right;
                    if (left) p->left->val = c->val;
                    else p->right->val = c->val;
                    delete c;
                }
                break;
            }
            else
            {
                p = c;
                c = c->val > key ? c->left:c->right;
            }
        }
        c = root->left;
        delete root;
        return c;
    }
};