class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(),low=0,high=n-1,mid;
        if(n==1){return nums[low];}
        
        while(low<=high){
            mid=(low+(high-low)/2);
            
            if(mid%2!=0 && nums[mid]==nums[mid-1] || mid%2==0 && nums[mid]==nums[mid+1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};