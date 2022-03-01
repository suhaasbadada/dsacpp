class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> rez(n);
        rez.push_back(0);
        
        for(int i=1;i<=n;i++){
            if(i%2==0){
                rez[i]=rez[i/2];
            }
            else{
                rez[i]=rez[i/2]+1;
            }
        }
        
        return rez;
    }
};