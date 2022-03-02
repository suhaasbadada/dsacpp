class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int k=searchWord.size();
        
        int idx=1;
        while(ss>>word){
            if(word.size()>=k){
                if(word.substr(0,k)==searchWord){
                    return idx;
                }
            }
            idx++;
        }
        
        return -1;
    }
};