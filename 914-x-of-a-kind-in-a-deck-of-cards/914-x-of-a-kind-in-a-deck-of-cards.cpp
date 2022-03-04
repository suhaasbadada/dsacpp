class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> mp;
        for(auto x:deck){mp[x]++;}
        int gcd=0;
        for(auto x:mp){
           gcd=__gcd(gcd,x.second);
        }
        
        return (gcd>=2);
    }
};
