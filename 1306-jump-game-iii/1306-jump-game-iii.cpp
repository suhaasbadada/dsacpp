class Solution {
public:
    bool dfs(vector<int>& arr,vector<bool>& viz,int i){
        if(i>=arr.size() || i<0 || viz[i]){return false;}
        if(arr[i]==0){return true;}
        viz[i]=true;
        
        return dfs(arr,viz,i+arr[i]) || dfs(arr,viz,i-arr[i]);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool> viz(n,false);
        return dfs(arr,viz,start);
    }
};