class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rs;
        rs.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            rs.push_back(nums[i]+rs[i-1]);
        }
        return rs;
    }
};