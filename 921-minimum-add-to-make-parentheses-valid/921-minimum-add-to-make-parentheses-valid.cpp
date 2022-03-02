class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        char open='(',close=')';
        int needed=0;
        for(auto x:s){
            if(x==open){
                st.push(open);
            }else{
                if(!st.empty() && st.top()==open){
                    st.pop();
                }else{
                    needed++;
                }
            }
        }
        needed+=st.size();
        
        return needed;
    }
};