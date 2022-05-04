class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1,ops=0;
        
        while(i<j){
            if(nums[i]+nums[j]==k){
                ops++;
                i++;
                j--;
                continue;
            }
            if(nums[i]+nums[j] > k){
                j--;
                continue;
            }else{
                i++;
                continue;
            }
        }
        
        return ops;
    }
};