class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        int mpe=INT_MAX;
        for(auto x:nums){
            if(x<=0){continue;}
            st.insert(x);
            mpe=min(mpe,x);
        }
        
        if(mpe>1){return 1;}
        
        while(true){
            if(st.find(mpe)==st.end()){
                return mpe;
            }
            mpe++;
        }

        return -1;
    }
};