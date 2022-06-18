class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size()+1,0);
        pre[0]=0;
        for(int i=0;i<nums.size();i++){
            pre[i+1]=pre[i]+nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            int ls=pre[i];
            int rs=pre[pre.size()-1]-pre[i]-nums[i];
            
            if(ls==rs){
                return i;
            }
        }
        
        return -1;
    }
};