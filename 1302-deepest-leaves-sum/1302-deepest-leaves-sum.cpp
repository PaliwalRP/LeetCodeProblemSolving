class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int levelSum = 0, curLevelCount = 0, nextLevelCount = 0;
        queue<TreeNode*> q;
        TreeNode *node;
        
        q.push(root);
        curLevelCount++;
        
        while(!q.empty()){
            node = q.front(); q.pop();
            curLevelCount--;
            levelSum += node->val;
            
            if(node->left){
                q.push(node->left);
                nextLevelCount++;
            }
            
            if(node->right){
                q.push(node->right);
                nextLevelCount++;
            }
            
            //go to next level
            if(curLevelCount == 0){
                curLevelCount = nextLevelCount;
                nextLevelCount = 0;
                //if there is still next level, clean levelSum
                if(!q.empty()){
                    levelSum = 0;
                }
            }
        }
        
        return levelSum;
    }
};