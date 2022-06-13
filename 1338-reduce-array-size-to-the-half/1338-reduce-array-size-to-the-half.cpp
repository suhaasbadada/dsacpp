class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size(),h=n/2,c=0,k=0;
        
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        vector<int> v;
        for(auto x:mp){
            v.push_back(x.second);
        }
    
        sort(v.begin(),v.end());
        
        for(int i=v.size()-1;i>=0;i--){
            c+=v[i];
            k++;
            if(c>=h){
                break;
            }
        }
        
        return k;
    }
};