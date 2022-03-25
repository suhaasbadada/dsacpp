class Solution {
public:
    static bool comp(vector<int> v1,vector<int> v2){
        return (v1[0]-v1[1] < v2[0]-v2[1]);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),comp);
        int n=costs.size(),s=0;
        
        int i=0,j=n-1;
        while(i<j){
            s+=(costs[i][0]+costs[j][1]);
            i++;
            j--;
        }

        return s;
    }
};