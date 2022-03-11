class Solution {
public:
    int jump(vector<int>& nums) {
        int rez=0,n=nums.size(),maxreach=0,curr=0;
        
        for(int i=0;i<n-1;i++){
            maxreach=max(maxreach,i+nums[i]);  
            if(i==curr){
                curr=maxreach;
                rez++;
            }
        }

        return rez;
    }
};