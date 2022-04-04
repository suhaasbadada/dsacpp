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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        vector<int> v;
        
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        swap(v[k-1],v[v.size()-1-k+1]);
        
        ListNode* rez=new ListNode(-1);
        ListNode* node=rez;
        
        for(auto x:v){
            ListNode* newnode=new ListNode(x);
            node->next=newnode;
            node=node->next;
        }

        return rez->next;
        
    }
};