class Solution {
public:
    string removeKdigits(string num, int k) {
      stack<char> st;  
      string rez="";
      for(int i=0;i<num.size();i++){
          while(!st.empty() && k>0 && st.top()>num[i]){
              st.pop();
              k--;
          }
          
          if(st.empty() && num[i]=='0'){
              continue;
          }
          st.push(num[i]);
      }
        
       while(k-- && !st.empty()){
           st.pop();
       }
       
       
       while(!st.empty()){
            rez+=st.top();
            st.pop();
        }
        reverse(rez.begin(),rez.end());

      return rez==""?"0":rez;
    }
};