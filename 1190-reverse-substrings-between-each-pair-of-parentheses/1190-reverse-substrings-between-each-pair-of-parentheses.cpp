class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        int n=s.size();
        string result="";
        
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string z="";
                while(!st.empty() && st.top()!='('){
                    z+=st.top();
                    st.pop();
                }
               st.pop();
               for(int j=0;j<z.size();j++){
                   st.push(z[j]);
               }
               continue;
            }
            st.push(s[i]);
        }
        
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        
        return result;
    }
};