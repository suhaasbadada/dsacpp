class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,char> ump1,ump2;
        
       for(int i=0;i<s.size();i++){
           char cs=s[i],cp=t[i];
           
           if(ump1.find(cs)==ump1.end()){
               ump1[cs]=cp;
           }
           
           if(ump2.find(cp)==ump2.end()){
               ump2[cp]=cs;
           }
           
           if(ump1[cs]!=cp || ump2[cp]!=cs){
               return false;
           }
       }
        
        return true;
    }
};