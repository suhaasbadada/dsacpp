class Solution {
public:
    int masked_bfs(vector<vector<int>>& graph,int n){
        int all=(1<<n)-1;           // to get all 1111....
        queue<pair<int,pair<int,int>>> q; // {node,{dist,mask}}
        set<pair<int,int>> viz;     // {node,mask}
        
        for(int i=0;i<n;i++){
            int mask=(1<<i); // 2^i
            q.push({i,{0,mask}}); 
        }
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int node=p.first;
            int dist=p.second.first;
            int mask=p.second.second;
            
            for(auto nghbr:graph[node]){
                int updated_mask=(mask | (1<<nghbr)); 
                
                if(updated_mask==all){
                    return dist+1;
                }else if(viz.find({nghbr,updated_mask})!=viz.end()){continue;}
                
                viz.insert({nghbr,updated_mask});
                q.push({nghbr,{dist+1,updated_mask}});
            }
        }
        
        return 0;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        
        if(n==1){return 0;}
        
        return masked_bfs(graph,n);
    }
};