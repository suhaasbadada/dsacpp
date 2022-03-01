class Solution {
public:
    vector<pair<int,int>> mov8={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    
    static bool canMove(vector<vector<int>>& grid,int x,int y,int n){
        return (x>=0 && x<n && y>=0 && y<n && grid[x][y]==0);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int source=grid[0][0],dest=grid[n-1][n-1];
        if(n==1 && source==0){return 1;}
        if(source!=dest || source!=0){
            return -1;
        }
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> viz(n,vector<bool>(n,false));
        q.push({{0,0},1});
        viz[0][0]=true;
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int cx=p.first.first;
            int cy=p.first.second;
            int d=p.second;
            
            for(auto x:mov8){
                int nx=cx+x.first;
                int ny=cy+x.second;
                if(canMove(grid,nx,ny,n) && !viz[nx][ny]){
                    if(nx==n-1 && ny==n-1){return d+1;}
                    q.push({{nx,ny},d+1});
                    viz[nx][ny]=true;
                }
            }
        }
        
        return -1;
    }
};