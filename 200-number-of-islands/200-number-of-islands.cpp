class Solution {
public:
    bool canMove(vector<vector<char>>& grid,int x,int y){
        int n=grid.size();
        int m=grid[0].size();
        
        return (x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1');
    }
    void bfs(vector<vector<char>>& grid,int sx,int sy){
        queue<pair<int,int>> q;
        q.push({sx,sy});
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        while(!q.empty()){
            pair<int,int> p=q.front();
            int x=p.first,y=p.second;
            q.pop();
            
            for(int i=0;i<4;i++){
                int movx=dx[i],movy=dy[i];
                
                if(canMove(grid,x+movx,y+movy)){
                    grid[x+movx][y+movy]='0';
                    q.push({x+movx,y+movy});
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int i,j;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};