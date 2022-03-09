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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){return NULL;}
        map<int,int> mp;
        ListNode* temp=head;
        
        while(temp){
            mp[temp->val]++;
            temp=temp->next;
        }
        
        ListNode* llset = new ListNode(0);
        ListNode* nodes = llset;
        
        for(auto p:mp){
            if(p.second==1){
                nodes->next=new ListNode(p.first);
                nodes=nodes->next;
            }
        }
        return llset->next;
    }
};