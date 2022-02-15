class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt=0;
        
        for(int i=0;i<items.size();i++){
            string t,c,n;
            t=items[i][0],c=items[i][1],n=items[i][2];
            bool b1,b2,b3;
            b1=(ruleKey=="type" && ruleValue==t);
            b2=(ruleKey=="color" && ruleValue==c);
            b3=(ruleKey=="name" && ruleValue==n);
            
            if(b1 || b2 || b3){cnt++;}
        }
        
        
        return cnt;
    }
};