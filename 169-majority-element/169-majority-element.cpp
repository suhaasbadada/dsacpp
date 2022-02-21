class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=0,n=nums.size(),c=0;
        
        for(int i=0;i<n;i++){
            if(c==0){
                maj=nums[i];
            }
            if(nums[i]==maj){
                c++;
            }else{
                c--;
            }
        }
        return maj;
    }
};