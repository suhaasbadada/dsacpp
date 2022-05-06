class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        
        for(auto x:s){
            
            if(st.empty() || st.top().first!=x){
                st.push({x,1});
            }else if(st.top().second < k-1){
                st.push({x,st.top().second+1});
            }else{
                int c=k-1;
                
                while(c--){
                    st.pop();
                }
            }
        }

        
        string z;
        while(!st.empty()){
            z+=st.top().first;
            st.pop();
        }
        
        reverse(z.begin(),z.end());
        
        return z;    
    }
};