class Solution {
public:
    void dfs(vector<int> adj[],vector<bool>&viz,int s){
        viz[s]=true;
        
        for(auto x:adj[s]){
            if(!viz[x]){
                dfs(adj,viz,x);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int tedges=connections.size();
                
        if(tedges < n-1){
            return -1;
        }
        
        vector<int> adj[n];
        vector<bool>viz(n,false);
        
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        int components=0;
        for(int i=0;i<n;i++){
            if(!viz[i]){
                dfs(adj,viz,i);
                components++;
            }
        }

        
        return components-1;
    }
};