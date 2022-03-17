class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0,n=s.size();
        char open='(',close=')';
        stack<int> st;
        
        for(int i=0;i<n;i++){
            if(s[i]==open){
                st.push(score);
                score=0;
            }else{
                int k=score;
                score+=st.top();
                
                if(k<1){
                    score+=1;
                }else{
                    score+=k;
                }

                st.pop();
            }
        }
        
        return score;
    }
};

