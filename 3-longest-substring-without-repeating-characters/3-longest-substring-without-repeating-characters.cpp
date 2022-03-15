class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size(),rez=0;
        unordered_set<char> st;
        
        while(i<n){
            if(st.find(s[i])==st.end()){
                st.insert(s[i]);
                i++;
                rez=max(rez,i-j);
            }else{
                st.erase(s[j]);
                j++;
            }
        }
        
        return rez;
    }
};
