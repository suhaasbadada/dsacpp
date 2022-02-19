class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> rez;
        int n=words.size(),k=pattern.size();
        
        for(int i=0;i<n;i++){
            unordered_map<char,char> ump1,ump2;
            string s=words[i];
            bool allok=true;
            for(int j=0;j<k;j++){
                char cs=s[j];
                char cp=pattern[j];
                
                 if(ump1.find(cs)==ump1.end()){
                    ump1[cs]=cp;
                }
                
                if(ump2.find(cp)==ump2.end()){
                    ump2[cp]=cs;
                }
                
                if(ump1[cs]!=cp || ump2[cp]!=cs){
                    allok=false;
                    break;
                }
                
            }
            
            if(allok){
                rez.push_back(s);
            }
        }
        
        
        return rez;
    }
};

/*

mee
abb

dkd
abb

*/