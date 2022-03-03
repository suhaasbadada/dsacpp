class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
         int rez=0,ap_size=0,d=0,c=0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==d){
                c++;
                if(c>=2){
                    rez+=(c-1);
                }
            }else{
                
                d=nums[i]-nums[i-1];
                c=1;
            }
        }
        
        return rez;
    }
};