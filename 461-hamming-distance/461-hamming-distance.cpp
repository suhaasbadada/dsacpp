class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamming=0;
        
        while(x|y){
            hamming+=((x&1)^(y&1));           
            if(x){
                x=(x>>1);
            }
            if(y){
                y=(y>>1);
            }
        }     
    
        return hamming;
    }
};