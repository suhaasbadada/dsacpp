class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n],radj[n];
        vector<bool>viz(n,false);
        for(auto e:connections){
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        
        int rev=0;
        queue<int> q;
        q.push(0);
            
        while(!q.empty()){
            int node=q.front();
            q.pop();
            viz[node]=1;
            
            for(auto nghbr:adj[node]){
                if(!viz[nghbr]){
                    rev++;
                    q.push(nghbr);                    
                }
            }
            
            for(auto nghbr:radj[node]){
                if(!viz[nghbr]){
                    q.push(nghbr);
                }
            }
        }
        return rev;
    }
};