class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp1,mp2;
        int n=t.size();
        
        for(int i=0;i<n;i++){
            char x=s[i],y=t[i];
            mp1[y]=x;
            mp2[x]=y;
        }
        

        string z1,z2;
        for(auto x:t){
            z1+=mp1[x];
        }
        for(auto x:s){
            z2+=mp2[x];
        }
        
        return z1==s && z2==t;
    }
};