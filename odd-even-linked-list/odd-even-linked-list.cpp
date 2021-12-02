/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* odd = head;
        ListNode* ans = odd;
        ListNode* even = head->next;
        ListNode* mark = even;
        while(even!=NULL){
            odd->next = even->next;
            if(odd->next!=NULL)
                odd = odd->next;
            if(even->next!=NULL){
                even->next = even->next->next;
                even = even->next;
            }
            else
                break;
        }
        odd->next = mark;
        return ans;
        
        
    }
};