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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* rez=new ListNode(-1);
        ListNode* node=rez;
        ListNode* temp=head;
        temp=temp->next;
        vector<int> sums;
        int cs=0;
        while(temp){
            if(temp->val==0){
                sums.push_back(cs);
                cs=0;
            }
            cs+=temp->val;
            temp=temp->next;
        }
        
        for(auto x:sums){
            ListNode* nn=new ListNode(x);
            node->next=nn;
            node=node->next;
        }
        
        
        
        return rez->next;
    }
};