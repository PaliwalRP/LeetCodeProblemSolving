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
    
    
    int dfs( TreeNode* root , unordered_map<int,int>& umap , int sum , int target){
        
        int count = 0;
        
        sum += root->val;
        int extra = sum - target ;
        if( umap.find(extra) != umap.end() ){
            count += umap[extra];
        }

        int a = 0 , b = 0 ;
        umap[sum]++;
        if( root->left){
            a = dfs(root->left,umap,sum,target);
        }
        if( root->right){
            b = dfs( root->right,umap,sum, target );
        }
        umap[sum]--;
        return a+b+count;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if( root==NULL ){
            return 0;
        }
        unordered_map<int,int> umap;
        umap[0] = 1 ;
        
        return dfs(root,umap,0,targetSum);
    }
};