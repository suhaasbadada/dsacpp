class Solution {
public:
    static bool isValid(int i,int j,int n,int m,vector<vector<char>>& maze){
        return (i>=0 && i<n && j>=0 && j<m && maze[i][j]=='.');
    }
    static bool exit(int x,int y,int n,int m){
        return (x==0 || x==n-1 || y==0 || y==m-1)?(true):(false);
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size();
        int sx=entrance[0],sy=entrance[1];
        maze[sx][sy] = '+';
        queue<pair<pair<int,int>,int>> q;
        q.push({{sx,sy},0});
        vector<pair<int,int>> mov={{1,0},{-1,0},{0,1},{0,-1}};
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            
            int cost=p.second;
            int cx=p.first.first;
            int cy=p.first.second;
            
            for(auto pt:mov){
                int nx=cx+pt.first,ny=cy+pt.second;
                
                if(isValid(nx,ny,n,m,maze)){
                    if(exit(nx,ny,n,m)){return cost+1;}
                    q.push({{nx,ny},cost+1});
                    maze[nx][ny]='+';
                }
            }
        }
        return -1;
    }
};