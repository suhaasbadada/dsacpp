const int MOD=1e9+7;
class Solution {
public:
    int countOrders(int n) {
        long rez=1;
        for(int i=1;i<=n;i++){
            rez*=i;
            rez*=(2*i-1);
            rez%=MOD;
        }
        return rez;
    }
};

/*

1 -> 1
2 -> 6
3 -> 90
4 -> 2520
5 -> 113400
6 -> 7484400

n!*(π [1,n]  (2*i-1))


n! ways for pickups and 1.3.5......(2n-1) ways deliveries
*/