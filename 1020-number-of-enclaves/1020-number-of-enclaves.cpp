class Solution {
public:
    vector<pair<int,int>> movs={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>&grid,int cx,int cy){
        if(cx<0 || cx>=grid.size() || cy<0 || cy>=grid[0].size()){return;}
        if(grid[cx][cy]!=1){return;}
        grid[cx][cy]=0;
        
        for(auto x:movs){
            int nx=cx+x.first;
            int ny=cy+x.second;
            dfs(grid,nx,ny);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==1){
                        dfs(grid,i,j);
                    }
                }
            }
        }
        
        int c=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    c++;
                }
            }
        }
        return c;
    }
};

/*

0 -> sea
1 -> land

dfs from boundary cells

*/