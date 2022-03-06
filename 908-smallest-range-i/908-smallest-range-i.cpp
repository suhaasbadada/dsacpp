class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int vmax=*max_element(nums.begin(),nums.end());
        int vmin=*min_element(nums.begin(),nums.end());
        return max(vmax-vmin-2*k,0);
    }
};
