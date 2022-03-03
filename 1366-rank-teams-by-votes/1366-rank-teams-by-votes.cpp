class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int n=votes.size();
        map<char,string> mp;
        
        for(auto x:votes){
            for(int i=0;i<x.size();i++){
                mp[x[i]].push_back(i+1+'0');
            }
        }
        
        for(auto x:mp){
            string ranks=x.second;
            sort(ranks.begin(),ranks.end());
            mp[x.first]=ranks;
        }
        
        vector<pair<string,char>> vp;
        
        for(auto x:mp){
            vp.push_back({x.second,x.first});
        }
        
        sort(vp.begin(),vp.end());
        string order;
        
        for(auto x:vp){
            order+=x.second;
        }
        
        return order;
    }
};