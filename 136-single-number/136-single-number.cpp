class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cxor=0;
        for(auto x:nums){
            cxor^=x;
        }
        return cxor;
    }
};