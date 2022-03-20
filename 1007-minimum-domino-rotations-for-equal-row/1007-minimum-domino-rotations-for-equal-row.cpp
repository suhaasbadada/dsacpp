class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> top_count(6),bottom_count(6),same(6);
        int n=tops.size();
        
        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                same[tops[i]-1]++;
            }
            top_count[tops[i]-1]++;
            bottom_count[bottoms[i]-1]++;
        }
        
        for(int i=0;i<6;i++){
            if(top_count[i]+bottom_count[i]-same[i]==n){
                return n-max(top_count[i],bottom_count[i]);
            }
        }
        
        return -1;
    }
};
