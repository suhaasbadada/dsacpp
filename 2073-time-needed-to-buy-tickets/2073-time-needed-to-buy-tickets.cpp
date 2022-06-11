class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int t=0,n=tickets.size();
        
        while(tickets[k]>0){
            for(int i=0;i<n;i++){
                if(tickets[i]>0){
                    tickets[i]--;
                    t++;
                }
                
                if(tickets[k]==0){
                    return t;
                }
            }
        }

        return t;
    }
};