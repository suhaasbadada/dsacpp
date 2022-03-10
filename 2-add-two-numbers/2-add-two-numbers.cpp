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
        
        while(t1 || t2 || carry){
            int cs=0;
            if(t1){cs+=t1->val; t1=t1->next;}
            if(t2){cs+=t2->val; t2=t2->next;}
            
            cs+=carry;
            carry=cs/10;
            
            ListNode* curr_sum=new ListNode(cs%10);
            node->next=curr_sum;
            node=node->next;
            
        }
        return rez->next;
    }
};
