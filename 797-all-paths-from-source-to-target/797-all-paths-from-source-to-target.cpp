class Solution {
    vector<vector<int>> paths;
public:
    void dfs(vector<vector<int>>& graph,vector<int> path,int s,int d){
        path.push_back(s);
        if(s==d){
            paths.push_back(path);
            return ;
        }
        
        for(auto x:graph[s]){
            dfs(graph,path,x,d);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> path;
        dfs(graph,path,0,n-1);
        
        return paths;
    }
};