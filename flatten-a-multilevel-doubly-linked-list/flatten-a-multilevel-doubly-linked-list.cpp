/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    Node* flatten(Node* head) {
        if(!head) return NULL;
        
        Node* cur = head;
        Node* tail = head;
        stack<Node*> stk;
        while(cur){
            if(cur->child){
                Node* Child = cur->child;
                if(cur->next){
                    stk.push(cur->next);
                    cur->next->prev = NULL;
                }
                cur->next = Child;
                Child->prev = cur;
                cur->child=NULL;
            }
            tail = cur;
            cur=cur->next;
        }
        
        while(!stk.empty()){
            cur=stk.top(); stk.pop();
            tail->next = cur;
            cur->prev=tail;
            while(cur){
                tail=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};