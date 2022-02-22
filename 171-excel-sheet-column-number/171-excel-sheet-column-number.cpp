class Solution {
public:
    int titleToNumber(string s) {
        int p=0,n=0;
        
        for(int i=s.length()-1;i>=0;i--){
            int c=(int)s[i]-64;
            n+=(pow(26,p)*c);
            p++;
        }
        return n;
    }
};
