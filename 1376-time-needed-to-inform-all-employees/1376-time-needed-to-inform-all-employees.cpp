class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        int root=headID;
        for(int i=0;i<n;i++){
            int u=manager[i];
            int v=i;
            
            if(u!=-1){
                adj[u].push_back(v);
            }
        }

        queue<pair<int,int>> q;
        q.push({root,informTime[root]});
        int fans=0;
        
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int node=p.first;
            int ctime=p.second;
            
            for(auto nghbr:adj[node]){
                q.push({nghbr,ctime+informTime[nghbr]});
            }
            fans=max(fans,ctime);            
        }
        
        return fans;
    }
};