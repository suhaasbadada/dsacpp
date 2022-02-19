class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int vmin=INT_MAX,rez=INT_MAX;
     
        for(auto x:nums){
            if(x%2!=0){
               x*=2;
            }
            vmin=min(vmin,x);
            pq.push(x);            
        }
        
        int diff=INT_MAX;
        
        while(!pq.empty() && pq.top()%2==0){
            int pmax=pq.top();
            pq.pop();
            diff=min(diff,pmax-vmin);
            vmin=min(vmin,pmax/2);
            pq.push(pmax/2);
        }
        
        return min(diff,pq.top()-vmin);        
    }
};


/*
20
10
8
6
2

all odd -> even, push in pq
while !pq empty and top%2==0
Update the difference (top - minval) constantly, while reducing the top/2.
Push top/2 onto the heap.
update minval
return min(diff,top-vmin)
*/