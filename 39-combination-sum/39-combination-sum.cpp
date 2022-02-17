class Solution {
public:
    void backtrack(int idx,vector<int>& v,vector<int>& dummy,int target,vector<vector<int>>& rez){
        if(target==0){
            rez.push_back(dummy);
            return ;
        }
        
        if(target<0 || idx==v.size()){
            return ;
        }
        
        backtrack(idx+1,v,dummy,target,rez);  // not choosing
        
        dummy.push_back(v[idx]); // choosing
        
        backtrack(idx,v,dummy,target-v[idx],rez);
        dummy.pop_back();

    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> dummy;
        vector<vector<int>> rez;
        backtrack(0,candidates,dummy,target,rez);
        
        return rez;
    }
};