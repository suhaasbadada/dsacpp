class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int s=0;
        for(auto x:arr){
           s+=x;
        }
        
        if(s%3!=0){return false;}
        s/=3;
        int cs=0,c=0;
        for(int i=0;i<arr.size();i++){
            cs+=arr[i];
            if(cs==s){
                cs=0;
                c++;
            }
        }
        
        return (c>=3);
    }
};
