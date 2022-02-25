// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    bool is_op(char c){
        return (c=='+'||c=='-'||c=='*'||c=='/');
    }
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        int n=S.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            char c=S[i];
            if(is_op(c)){
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                
                switch(c){
                    case '+':
                        st.push(n1+n2);
                        break;
                        
                    case '-':
                        st.push(n2-n1);
                        break;
                    
                    case '*':
                        st.push(n1*n2);
                        break;
                        
                    case '/':
                        st.push(n2/n1);
                        break;
                }
            }else{
                st.push(c-'0');
            }
        }
        return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends