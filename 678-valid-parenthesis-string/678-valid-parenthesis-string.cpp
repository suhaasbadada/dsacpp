class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open,star;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            char c=s[i];
            
            if(c=='('){
                open.push(i);
            }else if(c=='*'){
                star.push(i);
            }else{
                if(!open.empty()){
                    open.pop();
                }else{
                    if(!star.empty()){
                        star.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        
        while(!open.empty() && !star.empty()){
            int a,b;
            a=open.top();
            b=star.top();
            open.pop(); star.pop();
            if(a>b){return false;}
        }
        if(!open.empty()){return false;}
        return true;
    }
};
