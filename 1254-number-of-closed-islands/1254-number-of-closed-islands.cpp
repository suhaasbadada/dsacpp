class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int cx,int cy,int n,int m){
        if(cx<0 || cx>=n || cy<0 || cy>=m){return false;}
        if(grid[cx][cy]==1){return true;}
        grid[cx][cy]=1;
        
        bool u=dfs(grid,cx,cy+1,n,m);
        bool d=dfs(grid,cx,cy-1,n,m);
        bool l=dfs(grid,cx-1,cy,n,m);
        bool r=dfs(grid,cx+1,cy,n,m);
        
        return (u && d && l && r);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && dfs(grid,i,j,n,m)){
                    c++;
                }
            }
        }
        
        return c;
    }
};