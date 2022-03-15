class Solution {
public:
    int minSwaps(string s) {
        int n=s.size();
        stack<char> st;
        char open='[',close=']';

        
        for(int i=0;i<n;i++){
            if(s[i]==open){
                st.push(open);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        
        int k=st.size(),rez=0;
        
        if(k%2==0){
            rez=k/2;
        }else{
            rez=(k+1)/2;
        }
        
        return rez;
    }
};