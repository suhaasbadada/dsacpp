class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>> adj(n);
        int i,j;
        
        for(auto r:roads){
            int u=r[0],v=r[1];
            
            adj[u].insert(v);
            adj[v].insert(u);
        }
        
        
        int maxRank=0;
        
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                int rank=adj[i].size()+adj[j].size();                
                if(adj[i].find(j)!=adj[i].end()){ 
                    rank--;
                }
                maxRank=max(maxRank,rank);
            }
        }
        
        
        return maxRank;
    }
};