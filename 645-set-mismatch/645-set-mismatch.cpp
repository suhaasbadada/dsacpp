class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x=0,asum=nums[nums.size()-1],n=nums.size();
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                x=nums[i];
                // break;
            }
            asum+=nums[i];
        }
        
        int s=n*(n+1)/2;
        int y=s-asum+x;      
        
        return {x,y};
    }
};