class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
       unordered_map<char,vector<int>> ump;
            
       for(auto x:words){
            vector<int> temp(26,0);
            for(auto y:x){
                temp[y-97]++;               
            }
            for(int i=0;i<26;i++){
                if(temp[i]>0){
                    ump[char(i+97)].push_back({temp[i]});
                }
            }
       }
        vector<string> rez;
        for(auto x:ump){
           if(ump[x.first].size()==words.size()){
               int sz=*min_element(ump[x.first].begin(), ump[x.first].end());
               for(int i=0;i<sz;i++){
                  char c=x.first;
                   string s="";
                   s+=c;
                   rez.push_back(s);
               }
           }
        }
       
        return rez;
    }
};