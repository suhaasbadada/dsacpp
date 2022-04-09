class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        if(p1.second==p2.second){return p1.first < p2.first;}
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> rez;
        
        
        for(auto x:nums){
            mp[x]++;
        }
        
        vector<pair<int,int>> vp;
        for(auto x:mp){
            vp.push_back({x.first,x.second});
        }
        
        sort(vp.begin(),vp.end(),comp);
        
        
        int i=0;
        while(k--){
            rez.push_back(vp[i].first);
            i++;
        }
        
        
        return rez;
    }
};