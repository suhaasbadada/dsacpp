class Solution {
public:
    int minInsertions(string s) {
        int n=s.size(),c=0,i=0;
        stack<char> st;
        char open='(',close=')';
        
        while(i<n){
            if(s[i]==open){
                st.push(open);
                i++;
            }else{
                if(i+1<n){
                    if(s[i+1]==close){
                        if(!st.empty()){    
                            st.pop();
                            i+=2;
                        }else{
                            c+=1;
                            i+=2;
                        }
                    }else{
                        if(!st.empty()){
                            c+=1;
                            st.pop();
                            i++;
                        }else{
                            c+=2;
                            i++;
                        }
                    }
                }else{
                    if(!st.empty()){
                        st.pop();
                        c+=1;
                    }else{
                        c+=2;
                    }
                    i++;
                }
            }
        }
        
        c+=st.size()*2; 

        return c;
    }
};