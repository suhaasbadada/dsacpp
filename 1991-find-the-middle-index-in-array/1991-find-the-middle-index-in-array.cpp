class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre(n+1,0);
        
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+nums[i];
        }
        
        for(int i=0;i<n;i++){
            int ls=pre[i];
            int rs=pre[pre.size()-1]-pre[i]-nums[i];
            // cout<<ls<<" "<<rs<<endl;
            if(ls==rs){return i;}
        }
        
        return -1;
    }
};

/*

0 2 5 4 12 16   
16 14 11 12 4 0

0 1 0 4
4 3 4 0

*/