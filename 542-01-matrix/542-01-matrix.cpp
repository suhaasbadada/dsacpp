class Solution {
public:
    bool canMove(vector<vector<int>> &mat, int n, int m, int i, int j){
        return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == 1);
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> rez(n,vector<int>(m,INT_MAX));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    rez[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> mov={{-1,0},{1,0},{0,-1},{0,1}};
        
       while(!q.empty()){
           pair<int,int> p=q.front();
           int cx=p.first;
           int cy=p.second;
           q.pop();
           
           for(auto x:mov){
               int nx=cx+x.first;
               int ny=cy+x.second;
               
               if(canMove(mat,n,m,nx,ny)){
                   if(rez[nx][ny] > rez[cx][cy]){
                       rez[nx][ny] = rez[cx][cy] +1;
                       q.push({nx,ny});
                   }
               }
           }
       }
        
        return rez;
    }
};