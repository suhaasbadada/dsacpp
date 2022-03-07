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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){return list2;}
        if(list2==NULL){return list1;}
        if(list1==NULL && list2==NULL){return NULL;}
        
        ListNode* rez=new ListNode(-1);
        ListNode* node=rez;
        ListNode* t1=list1;
        ListNode* t2=list2;
        
        while(t1 && t2){
            if(t1->val > t2->val){
                ListNode* nn=new ListNode(t2->val);
                node->next=nn;
                node=node->next;
                t2=t2->next;
            }else if(t2->val > t1->val){
                ListNode* nn=new ListNode(t1->val);
                node->next=nn;
                node=node->next;
                t1=t1->next;
            }else{
                ListNode* n1=new ListNode(t1->val);
                ListNode* n2=new ListNode(t2->val);
                node->next=n1;
                node=node->next;
                node->next=n2;
                node=node->next;
                t1=t1->next;
                t2=t2->next;
            }
        }
        if(t1!=NULL){
            while(t1){
                ListNode* nn=new ListNode(t1->val);
                node->next=nn;
                node=node->next;
                t1=t1->next;
            }
        }
        if(t2!=NULL){
            while(t2){
                ListNode* nn=new ListNode(t2->val);
                node->next=nn;
                node=node->next;
                t2=t2->next;
            }
        }
        
        return rez->next;
    }
};