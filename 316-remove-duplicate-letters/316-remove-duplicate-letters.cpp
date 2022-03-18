class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> mp;
        for(auto x:s){mp[x]++;}
        unordered_map<char,bool> viz;
        string rez;
        
        for(auto x:s){
            mp[x]--;
            
            if(viz[x]){continue;}
            
            while(!rez.empty() && rez.back()>x && mp[rez.back()]>0){
                viz[rez.back()]=false;
                rez.pop_back();
            }
            
            viz[x]=true;
            rez+=x;
        }
        
        return rez;
    }
};