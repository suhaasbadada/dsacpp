class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> rez,v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        
        stack<int> st;
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[i]>=st.top()){
                st.pop();
            }
            if(st.empty()){
                rez.push_back(-1);
            }else{
                rez.push_back(st.top());
            }
            st.push(nums[i]);
        }
        
        reverse(rez.begin(),rez.end());
        for(int i=0;i<n;i++){
            v.push_back(rez[i]);
        }
        
        return v;
    }
};