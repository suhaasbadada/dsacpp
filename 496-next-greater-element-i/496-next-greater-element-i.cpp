class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ng,rez;
        
        int n1=nums1.size(),n2=nums2.size();
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            
            if(st.empty()){
                mp[nums2[i]]=-1;
            }else{
                mp[nums2[i]]=st.top();
            }
            
            st.push(nums2[i]);
        }
        
        for(int i=0;i<n1;i++){
            rez.push_back(mp[nums1[i]]);
        }
        
        
        
        return rez;
    }
};
// numbers unique