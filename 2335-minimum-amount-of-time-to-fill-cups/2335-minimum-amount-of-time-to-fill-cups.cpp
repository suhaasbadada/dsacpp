class Solution {
public:
    
    int fillCups(vector<int>& amount) {
        // c,w,h
        int n=amount.size(),k=0;
        if(amount[0]==0 && amount[1]==0 && amount[2]==0){return 0;}
        
        while(true){
            int fm,sm;
            sort(amount.begin(),amount.end());
            fm=amount[2],sm=amount[1];
            k++;
            amount[1]--; amount[2]--;
            if(amount[0]<=0 && amount[1]<=0 && amount[2]<=0){
                return k;
            }
        }
        return 0;
    }
};