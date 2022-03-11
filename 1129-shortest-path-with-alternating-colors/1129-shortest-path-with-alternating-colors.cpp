class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[n];
        for(auto x:redEdges){
            adj[x[0]].push_back({x[1],0});
        }
         for(auto y:blueEdges){
            adj[y[0]].push_back({y[1],1});
        }
        
        vector<int> dist(n,-1);
        queue<vector<int>> q;
        q.push({0,0,-1}); //start node,dist,color
        
        while(!q.empty()){
            vector<int> temp=q.front();
            q.pop();
            if(dist[temp[0]]==-1){
                dist[temp[0]]=temp[1];
            }
            
            for(auto &x:adj[temp[0]]){

                if(x.second!=temp[2] && x.first!=-1){
                    q.push({x.first,temp[1]+1,x.second});
                    x.first=-1;
                }
            }
        }
        return dist;
    }
};

