class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> rgraph[n],incoming(n,0),safe;
        
        for(int i=0;i<n;i++){
            int node=i;
            for(auto nghbr:graph[node]){
                rgraph[nghbr].push_back(node);
                incoming[node]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(incoming[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            
            for(auto nghbr:rgraph[node]){
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