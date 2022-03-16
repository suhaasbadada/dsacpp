class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int x=0;
        for(auto y:nums){
            x^=y;
        }
        return x;
    }
};