class Solution {
public:
    static bool rows_satisfied(int r,int n){
        long long rows=r;
        
        return (rows*(rows+1)/2)<=n;
    }
    int arrangeCoins(int n) {
        int low=0,high=n,mid,rez=0;
        
        while(low<=high){
            mid=(low+(high-low)/2);
            
            if(rows_satisfied(mid,n)){
                low=mid+1;
                rez=mid;
            }else{
                high=mid-1;
            }
        }
        return rez;
    }
};
