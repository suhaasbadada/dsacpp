class Solution {
public:
    static bool comp(vector<int> v1,vector<int> v2){
        if(v1[0]==v2[0]){
            return v1[1]>v2[1];
        }else{
            return v1[0]<v2[0];
        }
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int crossed=1;
        sort(intervals.begin(),intervals.end(),comp);
        
        vector<int> curr=intervals[0];
        for(int i=1;i<intervals.size();i++){
            int a=intervals[i][0],b=intervals[i][1];
            int c=curr[0],d=curr[1];
             if(c<=a && b<=d)
                continue;
            else{
                curr=intervals[i];
                crossed++;
            }
        }
        
        return crossed;
    }
};
