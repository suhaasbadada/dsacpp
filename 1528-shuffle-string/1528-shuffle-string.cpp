class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string z;
        vector<pair<int,char>> vp;
        for(int i=0;i<s.size();i++){
            vp.push_back({indices[i],s[i]});
        }
        sort(vp.begin(),vp.end());
        
        for(auto x:vp){
            z+=x.second;
        }
        
        return z;
    }
};