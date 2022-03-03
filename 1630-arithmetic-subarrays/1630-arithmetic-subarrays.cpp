class Solution {
public:
    static bool in_AP(vector<int> v){
        if(v.size()<=2){return true;}
        int d=v[1]-v[0];
        
        for(int i=1;i<v.size()-1;i++){
            if(v[i+1]-v[i]!=d){
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> rez;
        
        vector<pair<int,int>> query;
        for(int i=0;i<l.size();i++){query.push_back({l[i],r[i]});}
        
        for(auto x:query){
            vector<int> temp={nums.begin()+x.first,nums.begin()+x.second+1};
            sort(temp.begin(),temp.end());
            
            if(in_AP(temp)){
                rez.push_back(true);
            }else{
                rez.push_back(false);
            }
        }
        
        return rez;
    }
};