class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){continue;}
            int k=abs(nums[i]-nums[i-1])+1;
            nums[i]+=k;
            c+=k;
        }
        return c;
    }
};