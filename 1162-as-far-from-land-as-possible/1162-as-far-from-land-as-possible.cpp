class Solution {
public:
    static bool canMove(vector<vector<int>>& grid,int n,int cx,int cy){
        return (cx>=0 && cx<n && cy>=0 && cy<n && grid[cx][cy]==0);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        
        queue<pair<pair<int,int>,int>> q;
        vector<pair<int,int>> movs={{1,0},{-1,0},{0,1},{0,-1}};
        int land=0,rez=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    land++;
                    q.push({{i,j},0});
                }
            }
        }
        
        if(land==0 || land==n*n){return -1;}    
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int cx=p.first.first;
            int cy=p.first.second;
            int ctime=p.second;
            
            for(auto x:movs){
                int nx=cx+x.first;
                int ny=cy+x.second;
                
                if(canMove(grid,n,nx,ny)){
                    grid[nx][ny]=1;
                    q.push({{nx,ny},ctime+1});
                }
            }
            rez=ctime;
        }
    
        
        return rez;
    }
};

/*
 0 -> water
 1 -> land
 
 water cell(0) such that distance to nearest land cell is max
 infect ; same as rotting oranges problem
*/