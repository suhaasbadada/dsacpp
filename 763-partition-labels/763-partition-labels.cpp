class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        vector<int> rez;
        int i=0;
        
        while(i<s.length()){
            int lastIndex=mp[s[i]];
            int j=i+1;
            
            while(j<=lastIndex){
                lastIndex=max(lastIndex,mp[s[j]]);
                j++;
            }
            rez.push_back(lastIndex-i+1);
            i=lastIndex+1;
        }
        
        
        
        return rez;
    }
};