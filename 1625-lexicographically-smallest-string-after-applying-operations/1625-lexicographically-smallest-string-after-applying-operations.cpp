class Solution {
public:
     string add(string s,int a){
         for(int i=0;i<s.length();i++){
             if(i%2){
                 int dig=(s[i]-'0'+a);
                 dig%=10;
                 s[i]=dig+'0';
             }
         }
         return s;
     }
    
    string rotate(string s,int b){
        return (s.substr(s.length()-b)+s.substr(0,s.length()-b));
    }
    
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> calculated;
        queue<string> q;
        q.push(s);
        string rez=s;
        
        while(!q.empty()){
            string z=q.front();
            q.pop();
            
            string z1=add(z,a);
            string z2=rotate(z,b);
            
            rez=min(rez,z);
            
            if(calculated.find(z1)==calculated.end()){
                calculated.insert(z1);
                q.push(z1);
            }
            
            
            if(calculated.find(z2)==calculated.end()){
                calculated.insert(z2);
                q.push(z2);
            }
        }
        
        return rez;
    }
};