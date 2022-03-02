class Solution {
public:
    static bool is_subsequence(string s,string t){
        int i=0,j=0,n=t.size(),k=s.size(),c=0;
        
        while(i<n && j<k){
            if(s[j]==t[i]){
                c++;
                j++;
            }
            i++;
        }
        
        return (c==s.size());
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int c=0;
        unordered_map<string,int> mp;
        for(auto x:words){mp[x]++;}
        
        for(auto x:mp){
            if(is_subsequence(x.first,s)){
                c+=x.second;
            }
        }
        return c;
    }
};