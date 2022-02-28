class Solution {
public:
    bool sum_even(int n){
        int s=0;
        while(n){
            s+=(n%10);
            n/=10;
        }
        return !(s&1);
    }
    int countEven(int num) {
        int c=0;
        for(int i=1;i<=num;i++){
            if(sum_even(i)){
                c++;
            }
        }
        return c;
    }
};