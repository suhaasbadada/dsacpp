class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse edges + BFS
        int n=graph.size();
        vector<vector<int>> rgraph(n);
        vector<int> incoming(n,0),safe;

        for(int i=0;i<n;i++){
            int node=i;
            for(auto nghbr:graph[i]){
                rgraph[nghbr].push_back(i);
                incoming[i]++;
            }
        }
        
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(incoming[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int cnode=q.front();
            q.pop();
            safe.push_back(cnode);
            
            for(auto nghbr:rgraph[cnode]){
                incoming[nghbr]--;
                if(incoming[nghbr]==0){
                    q.push(nghbr);
                }
            }
        }
        
        sort(safe.begin(),safe.end());
        
        return safe;
    }
};