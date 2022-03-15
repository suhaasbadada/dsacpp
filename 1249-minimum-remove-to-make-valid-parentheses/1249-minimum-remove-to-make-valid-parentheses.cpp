class Solution {
public:
    string minRemoveToMakeValid(string s) {
        char open='(',close=')';
        stack<int> st;
        int n=s.size();
        vector<int> valid(n,false);
        
        for(int i=0;i<n;i++){
            if(s[i]==open){
                st.push(i);
            }else if(s[i]==close){
                if(!st.empty()){
                    valid[st.top()]=true;
                    valid[i]=true;
                    st.pop();
                }
            }else{
                valid[i]=true;
            }
        }
        
        string z;
        for(int i=0;i<n;i++){
            if(valid[i]){
                z+=s[i];
            }
        }
        
        return z;
    }
};
