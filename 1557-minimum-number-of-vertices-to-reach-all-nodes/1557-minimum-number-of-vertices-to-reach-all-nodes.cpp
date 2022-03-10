class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<int> incoming(n,0);
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            incoming[v]++;
        }
        
        vector<int> rez;
        
        for(int i=0;i<n;i++){
            if(incoming[i]==0){
                rez.push_back(i);
            }
        }
        
        return rez;
    }
};