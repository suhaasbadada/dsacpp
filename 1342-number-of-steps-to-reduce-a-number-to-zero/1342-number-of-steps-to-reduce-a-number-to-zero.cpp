class Solution {
public:
    int numberOfSteps(int num) {
        int steps=0;
        while(num){
            if(!(num&1)){
                num=(num>>1);
            }else{
                num--;
            }
            steps++;
        }
        return steps;
    }
};