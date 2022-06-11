class RecentCounter {
public:
    vector<int> pings;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int l=t-3000,r=t;
        int c=0;
        pings.push_back(t);
        
        for(auto x:pings){
            if(l<=x && x<=r){
                c++;
            }
        }
        
        return c;
    }
};
// [t-3000,t]
/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */