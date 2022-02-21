class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<int> v;
        
        for(int i=0;i<n1;i++){
            v.push_back(nums1[i]);
        }
        
        for(int i=0;i<n2;i++){
            v.push_back(nums2[i]);
        }
        
        sort(v.begin(),v.end());

        if(v.size()%2==0){
            int h=v.size()/2;
            
            return (v[h-1]+v[h])/2.0;
        }
        return v[v.size()/2];
    }
};