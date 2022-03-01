class Solution {
public:
    vector<pair<int,int>> movs={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> rez;
    static bool canMove(vector<vector<int>>& heights,int n,int m,int x,int y){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    
    void bfs(vector<vector<int>>& heights,queue<pair<int,int>>& q,vector<vector<bool>>&viz,int n,int m){
       
        while(!q.empty()){
            auto p=q.front(); q.pop();
            int cx=p.first;
            int cy=p.second;
            
            for(auto x:movs){
                int nx=cx+x.first;
                int ny=cy+x.second;
                
                if(canMove(heights,n,m,nx,ny) && heights[nx][ny]>=heights[cx][cy] && !viz[nx][ny]){
                    q.push({nx,ny});
                    // rez.push_back({nx,ny});
                    viz[nx][ny]=true;
                }
            }
        }
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        queue<pair<int,int>> pacific,atlantic;
        vector<vector<bool>> viz_atl(n,vector<bool>(m,false));
        vector<vector<bool>> viz_pac(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    pacific.push({i,j});
                    viz_pac[i][j]=true;
                }
                if(i==n-1 || j==m-1){
                    atlantic.push({i,j});
                    viz_atl[i][j]=true;
                }
            }
        }
        
        bfs(heights,pacific,viz_pac,n,m); 
        bfs(heights,atlantic,viz_atl,n,m); 
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(viz_pac[i][j] && viz_atl[i][j]){
                    rez.push_back({i,j});
                }
            }
        }
        
        
        return rez;        
    }
};