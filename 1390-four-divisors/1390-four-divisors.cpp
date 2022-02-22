class Solution {
public:
    int divsum(int n){
        int d=0,sum=0;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i==0){
                if((n/i)!=i){
                    d+=2;
                    sum+=(n/i)+i;
                }else{
                    d++;
                    sum+=i;
                }
            }
        }
        if(d!=4){sum=0;}
        return sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int rez=0;
        for(auto x:nums){
            rez+=divsum(x);
        }
        return rez;
    }
};