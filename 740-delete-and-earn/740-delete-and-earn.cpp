const int LIMIT=20000;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int>sums(LIMIT,0);
        for(auto x:nums){
            sums[x]+=x;
        }
        
        vector<int> dp(LIMIT,0);
        dp[0]=0;
        dp[1]=sums[1];
        
        for(int i=2;i<LIMIT;i++){
            dp[i]=max(dp[i-1],dp[i-2]+sums[i]);
        }
        
        return dp[LIMIT-1];
    }
};