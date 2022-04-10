class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(auto x:ops){
            if(x=="C"){
                st.pop();
            }else if(x=="D"){
                st.push(st.top()*2);
            }else if(x=="+"){ 
                int cs=0;
                cs+=st.top();
                int push_again=st.top();
                st.pop();
                cs+=st.top();
                st.push(push_again);
                st.push(cs);
            }else{
                st.push(stoi(x));
            }
        }
        
        int rez=0;
        while(!st.empty()){
            rez+=st.top();
            st.pop();
        }
        
        return rez;
    }
};