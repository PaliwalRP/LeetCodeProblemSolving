/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
   public:
    unordered_map<Node*, Node*> seen;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return head;
        }
        if (seen.count(head) > 0) {
            return seen[head];
        }
        Node* node = new Node(head->val);
        seen[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};