class Solution {
public:
    string simplifyPath(string path) {
        string s;
        stringstream ss(path);
        vector<string> v;
        
        while(getline(ss, s, '/')){
           if(s==""||s=="."){continue;}
          
           if(s==".." && v.size()!=0){
                v.pop_back();
            }else if(s!=".."){
                v.push_back(s);
            }
        }
        if(v.size()==0){return "/";}
        string z="";
        for(int i=v.size()-1;i>=0;i--){
            z="/"+v[i]+z;
        }
        return z;
    }
};