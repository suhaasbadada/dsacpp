class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,vector<int>> mp;
        int i=0;
        for(auto x:nums){
            mp[x].push_back(i);
            i++;
        }
       
        for(auto x:mp){
            auto v=x.second;
            
            if(v.size()==1){continue;}
            for(int i=0;i<v.size()-1;i++){
                if(v[i+1]-v[i]<=k){return true;}
            }
        }
        return false;
    }
};