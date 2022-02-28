class Solution {
public:    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        vector<vector<int>> viz(n,vector<int>(m,0));
        vector<pair<int,int>> movs={{1,0},{-1,0},{0,1},{0,-1}};
        int si=0;
        /* perform bfs on grid2 if grid1{i,j} && grid2{i,j} ==1 
           store all the indices
           if any of this index is 0 in grid1 then dont add
        */
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid1[i][j]==1 && grid2[i][j]==1 && viz[i][j]==0){
                    queue<pair<int,int>> q;
                    vector<pair<int,int>> indices;
                    
                    q.push({i,j});
                    viz[i][j]=1;
                    
                    while(!q.empty()){
                        auto p=q.front();
                        int cx=p.first;
                        int cy=p.second;
                        q.pop();
                        
                        for(auto x:movs){
                            int nx=cx+x.first;
                            int ny=cy+x.second;
                            
                            if(nx>=0 && nx<n && ny>=0 && ny<m && grid2[nx][ny]==1 && viz[nx][ny]==0){
                                viz[nx][ny]=1;
                                indices.push_back({nx,ny});
                                q.push({nx,ny});
                            }
                        }
                    }
                    bool no_mismatch=true;
                    for(auto p:indices){
                        if(grid1[p.first][p.second]==0){
                            no_mismatch=false;
                            break;
                        }
                    }
                                 
                    if(no_mismatch){
                        si++;
                    }

                }
            }
        }
        
        
        return si;
    }
};