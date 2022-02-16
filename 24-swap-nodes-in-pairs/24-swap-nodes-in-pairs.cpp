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
    ListNode* swapPairs(ListNode* head) {
        if(head!=NULL && head->next!=NULL){
            ListNode* curr=head;
            ListNode* cn=head->next;
            ListNode* temp;
            head=head->next;
            
            while(curr!=NULL && curr->next!=NULL){
                temp=cn->next;
                curr->next=temp;
                
                if(curr->next!=NULL && curr->next->next!=NULL){
                    curr->next=curr->next->next;
                }
                cn->next=curr;
                curr=temp;
                if(curr!=NULL){
                    cn=curr->next;
                }
                
            }
        }
        
        return head;
    }
};