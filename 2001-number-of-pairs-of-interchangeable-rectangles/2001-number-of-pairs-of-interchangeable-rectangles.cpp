class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long rez=0;
        
        unordered_map<double,long long> mp;
        for(auto x:rectangles){
            mp[(double)x[0]/x[1]]++;
        }
        
        for(auto x:mp){
            long long n=x.second;
            rez+=(n*(n-1)/2);
        }            
    
        
        return rez;
    }
};