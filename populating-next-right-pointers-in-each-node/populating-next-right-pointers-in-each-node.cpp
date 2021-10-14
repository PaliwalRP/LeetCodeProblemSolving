/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) 
    {
        // Empty Tree
        if(!root)
            return root;
        
        modifyRightNode(root);
        
        return root;
    }
    
    void modifyRightNode(Node* root)
    {
        if(root->left == NULL)
            return;
        
        root->left->next = root->right;
        
        if(root->next)
            root->right->next = root->next->left;
        
        modifyRightNode(root->left);
        modifyRightNode(root->right);
    }
};