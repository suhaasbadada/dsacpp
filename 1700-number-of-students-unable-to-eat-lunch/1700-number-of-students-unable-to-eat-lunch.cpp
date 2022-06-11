class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int pref0=0,pref1=0,n=sandwiches.size();
        
        for(auto x:students){
            if(x==0){
                pref0++;
            }else{
                pref1++;
            }
        }
        
        int c=0,ind=0;
        
        for(int i=0;i<n;i++){
            if(sandwiches[i]==0){
                pref0--;
            }else{
                pref1--;
            }
            
            if(pref0<0 || pref1<0){
                ind=i;
                break;
            }
        }
        
        if(pref0==0 && pref1==0){return 0;}
        return n-ind;
    }
};

// 0-> circular, 1-> square