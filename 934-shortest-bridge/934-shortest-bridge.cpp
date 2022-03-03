class Solution {
public:
    vector<pair<int,int>> movs={{0,1},{0,-1},{1,0},{-1,0}};
    static bool cantMove(vector<vector<int>>& grid,int cx,int cy,int n,int m){
        return (cx<0 || cx>=n || cy<0 || cy>=m || grid[cx][cy]==0);
    }
    void dfs(vector<vector<int>>& grid,int cx,int cy,vector<pair<int,int>>& vp){
        if(cantMove(grid,cx,cy,grid.size(),grid[0].size())){return ;}
        grid[cx][cy]=0;
        vp.push_back({cx,cy});
        
        for(auto x:movs){
            int nx=cx+x.first;
            int ny=cy+x.second;
            dfs(grid,nx,ny,vp);
        }
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),islands=0;
        vector<pair<int,int>> i1,i2;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   if(grid[i][j]==1){
                       islands++;
                       if(islands==1){
                           dfs(grid,i,j,i1);
                       }else if(islands==2){
                           dfs(grid,i,j,i2);
                       }else{
                           break;
                       }
                   }
            }
        }
        
        int dist=INT_MAX;
            
        for(auto x:i1){
            for(auto y:i2){
                int manhattan=abs(x.first-y.first)+abs(x.second-y.second);
                // cout<<manhattan<<" ";
                dist=min(dist,manhattan-1);
            }
        }
        
        
        return dist;
    }
};


/*
1 -> land
0 -> water
2 islands in grid
can change water -> land ( 0 -> 1 ) to form 2 islands to 1
smallest number of flips reqd

0 1
1 0

1 1 1 1 1
1 0 0 0 1
1 0 1 0 1
1 0 0 0 1
1 1 1 1 1
*/