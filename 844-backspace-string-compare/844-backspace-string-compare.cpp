class Solution {
public:
    stack<char> typed(string s){
        stack<char> st;
        int n=s.length();
        
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                if(!st.empty()){
                    st.pop();
                }
            }else{
                st.push(s[i]);
            }
        }
        
        return st;        
    }
    bool backspaceCompare(string s, string t) {
        return typed(s)==typed(t);
    }
};