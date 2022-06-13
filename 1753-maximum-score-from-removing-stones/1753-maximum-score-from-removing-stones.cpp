class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);pq.push(b);pq.push(c);
        int k=0;
        
        while(pq.size()>1){
            int k1=pq.top(); 
            pq.pop();
            int k2=pq.top();
            pq.pop();
            
            k++;
            k1--;
            k2--;
            
            if(k1>0){
                pq.push(k1);
            }
            
            if(k2>0){
                pq.push(k2);
            }
        }
        
        return k;
    }
};