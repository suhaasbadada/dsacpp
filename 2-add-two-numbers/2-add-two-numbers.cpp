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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rez=new ListNode(-1);
        ListNode* node=rez;
        ListNode* t1=l1;
        ListNode* t2=l2;
        int carry=0;
        
        
        while(l1 || l2 || carry){
            int s=0;
            if(l1!=NULL){
                s+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                s+=l2->val;
                l2=l2->next;
            }
            
            s+=carry;      
            carry=s/10;
            // cout<<s<<endl;
            
            ListNode* curr_sum=new ListNode(s%10);
            node->next=curr_sum;
            node=node->next;
        }
            
            
        return rez->next;
    }
};