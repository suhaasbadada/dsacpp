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
    ListNode* shift(ListNode* head){
        if (head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* temp=head;
        while (temp->next->next) {
            temp = temp->next;
        }

        temp->next->next = head;

        head = temp->next;

        temp->next= NULL;
        
        return head;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        k=k%n;
        for(int i=0;i<k;i++){
            head=shift(head);
        }        

        return head;
    }
};