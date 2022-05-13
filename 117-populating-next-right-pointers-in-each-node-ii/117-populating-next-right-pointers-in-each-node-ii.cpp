class Solution {
public:
    Node* connect(Node* root) {
        Node* tmp = root;
        
        Node* dummy = new Node(-1);
        
        while(root) {
            Node* curParent = root;
            Node* prev = dummy;
            
            while(curParent) {
                if (curParent->left) {
                    prev->next = curParent->left;
                    prev = prev->next;
                }

                if (curParent->right) {
                    prev->next = curParent->right;
                    prev = prev->next;
                }

                curParent = curParent->next;
            }
            
            root = dummy->next;
            dummy->next = nullptr;
        }
        
        return tmp;
    }
};