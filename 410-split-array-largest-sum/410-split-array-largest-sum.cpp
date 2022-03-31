class Solution {
private:
    bool isPossible(vector<int> nums,int mid,int m){
        int limit = 1;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            
            if(sum > mid){
                limit ++;
                sum = nums[i];
            }
        }
        
        if(limit > m){
            return false;
        }
        else{
            return true;
        }
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int sum =0;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            maxi = max(maxi,nums[i]);
        }
        if(m==nums.size()){
            return maxi;
        }
        
        int s = maxi;
        int e = sum;
        int ans = 0;
        
        while(s<=e){
            int mid = s + (e-s)/2;
            
            if(isPossible(nums,mid,m)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;
    }
};