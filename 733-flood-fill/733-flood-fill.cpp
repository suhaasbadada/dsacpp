class Solution {
public:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        int prev=image[sr][sc],m=image.size(),n=image[0].size();
        image[sr][sc]=newColor;
        int x[4]={0,0,1,-1},y[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int newX=x[i]+sr,newY=y[i]+sc;
            if(newY>=0 and newY<n and newX>=0 and newX<m and image[newX][newY]==prev)
                floodFill(image,newX,newY,newColor);
        }
        return image;
    }
};