class Solution {
public:
    void dfs(vector<int> adj[],int s,vector<bool>& viz){
        viz[s]=true;
        
        for(auto x:adj[s]){
            if(!viz[x]){
                dfs(adj,x,viz);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool>viz(n,false);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!viz[i]){
                dfs(adj,i,viz);
                provinces++;
            }
        }
        
        return provinces;
    }
};