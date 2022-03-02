class Solution {
public:
    set<vector<int>> st;
    void choose_or_not(int idx,vector<int>& nums,vector<int>& temp,vector<vector<int>>&rez){
        if(idx==nums.size()){
            st.insert(temp);
            return ;
        }else{
            //choose
            temp.push_back(nums[idx]);
            choose_or_not(idx+1,nums,temp,rez);
            //dont choose
            temp.pop_back();
            choose_or_not(idx+1,nums,temp,rez);
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> rez;
        vector<int> temp;
        choose_or_not(0,nums,temp,rez);
        for(auto x:st){
            rez.push_back(x);
        }
        
        return rez;
    }
};