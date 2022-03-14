class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int c=0;
        for(auto x:stones){
            if(jewels.find(x)!=string::npos){
                c++;
            }
        }
        return c;
    }
};