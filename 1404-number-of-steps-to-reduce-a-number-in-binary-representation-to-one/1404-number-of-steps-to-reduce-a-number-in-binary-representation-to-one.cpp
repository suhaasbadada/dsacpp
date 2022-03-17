class Solution {
public:
    int numSteps(string s) {
        int n=s.size(),i=n-1,c=0;
        
        while(i>0){
            if(s[i]=='0'){
                i--;
                continue;
            }
            
            while(i>=0 && s[i]=='1'){
                i--;
            }
            c++;
            if(i<0){
                return n+c;
            }
            s[i]='1';
        }
        
        return n-1;
    }
};
