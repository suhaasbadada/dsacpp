class Solution {
public:
    int MOD=1e9+7;
    int count(string s,char c){
        int n=s.size(),rez=0;
        long long occ=0;
        
        for(int i=0;i<n;i++){
            if(s[i]==c){
                occ++;
            }else{
                rez+=((occ*(occ+1))/2)%MOD;
                occ=0;
            }
        }
        
        rez+=((occ*(occ+1))/2)%MOD;
        
        return rez;
    }
    int countHomogenous(string s) {
        int ans=0;
        set<char> st;
        for(auto x:s){st.insert(x);}
        
        for(auto x:st){
           
           ans=(ans+count(s,x))%MOD;
        }
        
        return ans%MOD;
    }
};