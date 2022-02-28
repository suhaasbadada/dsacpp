class Solution {
public:
    string range(int a,int b){
        return (a==b)?(to_string(a)):(to_string(a)+"->"+to_string(b));
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        vector<string> rez;
        if(n==0){return rez;}
        
        int a=nums[0];
        
        for(int i=1;i<n;i++){
            if(nums[i]-1!=nums[i-1]){
                rez.push_back(range(a,nums[i-1]));
                a=nums[i];
            }
            
        }
        rez.push_back(range(a,nums.back()));
        return rez;
    }
};