class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string z;
        map<char,int> mp;
        
        for(auto x:s){ mp[x]++; }        
        priority_queue<pair<char,int>> pq;
        for(auto x:mp){ pq.push({x.first,x.second}); }
        
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            
            int i=0;
            while(i<repeatLimit && i<p.second){
                z+=p.first;
                i++;
            }
            
            if(p.second > repeatLimit && !pq.empty()){
                auto np=pq.top();
                pq.pop();
                
                z+=np.first;
                if(np.second > 1){
                    pq.push({np.first,np.second-1});
                }
                pq.push({p.first,p.second-i});
            }
        }
        

        return z;
    }
};
/*

3
z -> 2
c -> 4
a -> 1

2
a -> 4
b -> 3


*/