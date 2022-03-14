class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string z;
        int k=0,n=s.size();
        
        for(int i=0;i<n;i++){
            if(k<spaces.size() && i==spaces[k]){
                k++;
                z+=" ";
            }
            z+=s[i];
        }
        
        return z;
    }
};