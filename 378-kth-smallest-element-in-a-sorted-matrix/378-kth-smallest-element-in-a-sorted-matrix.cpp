class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto x:matrix){
            for(auto y:x){
                pq.push(y);
            }
        }
        k--;
        while(k--){
            pq.pop();
        }
        
        return pq.top();
    }
};
// 1 5 9 10 11 12 13 13 15