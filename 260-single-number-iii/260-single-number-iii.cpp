class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<int> v;
        for(auto x:mp){
            if(x.second==1){
                v.push_back(x.first);
            }
        }
        return v;
    }
};