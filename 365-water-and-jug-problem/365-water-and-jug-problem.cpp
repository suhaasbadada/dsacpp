class Solution {
public:
    bool canMeasureWater(int j1_cap, int j2_cap, int target) {
        if(target > j1_cap+j2_cap){return false;}
        if(target==j1_cap || target==j2_cap || target==j1_cap+j2_cap){return true;}
        
        return (target%(__gcd(j1_cap,j2_cap))==0);
    }
};