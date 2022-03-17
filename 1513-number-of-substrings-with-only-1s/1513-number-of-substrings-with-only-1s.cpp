class Solution {
public:
    int MOD=1e9+7;
    int numSub(string s) {
        int n=s.size(),rez=0;
        long long ones=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ones++;
            }else{
                rez+=((ones*(ones+1))/2)%MOD;
                ones=0;
            }
        }
        
        rez+=((ones*(ones+1))/2)%MOD;
        
        return rez;
    }
};