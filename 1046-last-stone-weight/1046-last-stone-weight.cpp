class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        
        for(auto x:stones){
            pq.push(x);
        }
        int x,y;
        while(!pq.empty()){
            x=pq.top();
            pq.pop();
            
            if(!pq.empty()){
                y=pq.top();
                pq.pop();
            }else{
                return x;
            }
            
            pq.push(x-y);
        }
        return -1;
    }
};