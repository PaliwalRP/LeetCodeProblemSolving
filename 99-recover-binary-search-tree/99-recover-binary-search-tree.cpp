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
    TreeNode *cur, *prev;
    TreeNode *first, *second;
    
    void doWork(){
        //do work related to this problem
        if(prev != nullptr && prev->val > cur->val){
            if(first == nullptr){
                first = prev;
                // cout << "first: " << prev->val << endl;
            }
            /*
            also set second when first == nullptr,
            this is so deal with the case that 
            first and second may be consecutive
            */
            second = cur;
            // cout << "second: " << cur->val << endl;
        }
        //maintain the "prev" pointer
        prev = cur;
    };
    
    void recoverTree(TreeNode* root) {
        cur = root;
        prev = nullptr;
        first = second = nullptr;
        
        //the framework is Morris traversal
        while(cur){
            if(cur->left){
                //find its predecessor in its left subtree
                TreeNode* pred = cur->left;
                while(pred->right != nullptr && pred->right != cur){
                    pred = pred->right;
                }
                
                if(pred->right == nullptr){
                    /*
                    connect the predecessor's right to cur,
                    so we can come back to cur later
                   */
                    pred->right = cur;
                    /*
                    now that it is ensured that we can go back to cur later,
                    we can go to its left subtree safely
                    */
                    cur = cur->left;
                }else{
                    //here pred->right == cur
                    
                    doWork();
                    // cout << cur->val << endl;
                    
                    pred->right = nullptr;
                    /*
                    we have visit cur's left subtree and cur itself,
                    so go to its right subtree
                    */
                    cur = cur->right;
                }
            }else{
                doWork();
                // cout << cur->val << endl;
                cur = cur->right;
            }
        }
        
        if(first != nullptr && second != nullptr){
            swap(first->val, second->val);
        }
    }
};