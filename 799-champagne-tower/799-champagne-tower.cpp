class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> glasses(101,vector<double>(101,0));
        glasses[0][0]=(double)poured;
        double cap=1.00;
        for(int r=0;r<=query_row;r++){
            for(int c=0;c<=r;c++){
                if(glasses[r][c] > cap){
                    double excess=glasses[r][c]-cap;
                    double pours_down=excess/2.00;
                    glasses[r][c]=1;
                        
                    glasses[r+1][c]+=pours_down;
                    glasses[r+1][c+1]+=pours_down;
                }
            }
        }
        return glasses[query_row][query_glass];
    }
};

