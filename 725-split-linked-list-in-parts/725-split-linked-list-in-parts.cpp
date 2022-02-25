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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<int> all_nodes;
        int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            n++;
            all_nodes.push_back(temp->val);
            temp=temp->next;
        }
        
        int each_grp=(n/k);
        vector<int> gsz(k,each_grp);
        int remaining=n-(each_grp)*k;
        
        for(int i=0;i<remaining;i++){
            gsz[i]=gsz[i]+1;
            // remaining--;
        }
        
        vector<ListNode*> rez;
        
        int ctr=0;
        int lbegin=0;
        while(ctr!=k){
            ListNode* rhead=new ListNode(-1);
            ListNode* node=rhead;
            // cout<<lbegin<<" "<<lbegin+gsz[ctr]<<endl;
            for(int i=lbegin;i<lbegin+gsz[ctr];i++){
                ListNode* ele=new ListNode(all_nodes[i]);
                node->next=ele;
                node=node->next;
            }
            lbegin+=gsz[ctr];
            rez.push_back(rhead->next);
            ctr++;
        
        }
               
        
        
        return rez;
    }
};