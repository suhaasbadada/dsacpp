class Solution {
public:
    bool good(string s){
        bool flag=false; // 0,1,8
        for(auto x:s){
            if(x=='3'||x=='4'||x=='7'){
                return false;
            }
            if(x=='2'||x=='5'||x=='6'||x=='9'){
                flag=true;
            }
        }
        return flag;
    }
    int rotatedDigits(int n) {
        int i=1;
        int c=0;
        for(int i=1;i<=n;i++){
            if(good(to_string(i))){
                cout<<i<<" ";
                c++;
            }
        }
        return c;
    }
};