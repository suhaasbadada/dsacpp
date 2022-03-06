class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size(),j=mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> kweakest;
        for(int i=0;i<n;i++){
            pq.push({count(mat[i].begin(),mat[i].end(),1),i});
        }
        while(k--){
            kweakest.push_back(pq.top().second);
            pq.pop();
        }
        return kweakest;
    }
};

/*

1 -> soldiers
0 -> civilians

*/