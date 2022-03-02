class Solution {
public:
    bool isSubsequence(string s, string t) {
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
};