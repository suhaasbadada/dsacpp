class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> blocked;
        unordered_set<string> viz;
        string start="0000";
        for(auto x:deadends){
            blocked.insert(x);
        }
        
        if(blocked.find(target)!=blocked.end()){return -1;}
        if(target==start){return 0;}
        
        queue<pair<string,int>> q;
        int turns=0;
        
        q.push({start,0});
        viz.insert(start);
        vector<int> x = {-1,1};
        
        while(!q.empty()){
            auto p=q.front(); q.pop();
            string cpwd=p.first;
            int steps=p.second;
            
            if(blocked.find(cpwd)!=blocked.end()){continue;}
            
            for(int i=0;i<4;i++){
                string z=cpwd;
                
                for(int j=0;j<2;j++){
                    z[i]=(((z[i]-'0')+10+x[j])%10 + '0');
                    
                    if(blocked.find(z)!=blocked.end()){continue;}
                    if(z==target){ 
                        return steps+1; 
                    }
                    if(viz.find(z)==viz.end()){
                        viz.insert(z);
                        q.push({z,steps+1});
                    }   
                    z=cpwd;
                }
                
                
            }
        }     
        
        return -1;
    }
};