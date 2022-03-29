class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int n=nums.size();
    int repeating[n+1]; 
    memset(repeating,0, sizeof(repeating)); 

    int i;
    for(i=0;i<n;i++){
    	repeating[nums[i]-1]+=1;
    }
    int ans;
    for(i=0;i<n;i++){
    	if(repeating[i]>1){
    		ans=i+1;
            break;
    	}
    }
    return ans;
}
};