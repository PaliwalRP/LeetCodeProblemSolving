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
private:
    vector<int> preOrder;
    
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodes;
        
        if(root == NULL)//in case the input is empty
            return preOrder;
        
        nodes.push(root);
        
        while(!nodes.empty()){
            TreeNode *tmpNode = nodes.top();
            
            //psuh the root's value into a vector
            preOrder.push_back(tmpNode -> val);
            
            nodes.pop();//pop the tmpNode from stack
            
            //because statk is LIFO, the right node is latter than left node
            if(tmpNode -> right != NULL)    nodes.push(tmpNode -> right);
            if(tmpNode -> left  != NULL)    nodes.push(tmpNode -> left);
        }
        
        return preOrder;
    }
};