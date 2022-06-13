class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int r=rowSum.size(),c=colSum.size();
        vector<vector<int>>mat(r,vector<int>(c,0));
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int k=min(rowSum[i],colSum[j]);
                rowSum[i]-=k;
                colSum[j]-=k;
                mat[i][j]+=k;
            }
        }
        return mat;
    }
};