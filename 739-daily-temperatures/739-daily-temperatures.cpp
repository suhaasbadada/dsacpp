#define pb push_back
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n=temperatures.size();
        vector<int> rez;
        
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            
            if(st.empty()){
                rez.pb(0);
            }
            else{
                rez.pb(st.top()-i);
            }
            
            st.push(i);
        }
        
        reverse(rez.begin(),rez.end());
        
        
        return rez;
    }
};