class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto x:s){
            if(x=='a'){
                st.push(x);
            }else if(x=='b'){
                if(st.empty() || st.top()!='a'){return false;}
                st.push(x);
            }else if(x=='c'){
                 if(st.empty() || st.top()!='b'){return false;}
                 st.pop();
                 if(st.empty() || st.top()!='a'){return false;}
                 st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
};