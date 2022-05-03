class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> backup=nums;
        sort(backup.begin(),backup.end());
        int n=nums.size();
        int l=n,r=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=backup[i]){
                l=min(l,i);
                r=max(r,i);
            }
        }
        
        return (r-l>=0?(r-l+1):0);
    }
};
