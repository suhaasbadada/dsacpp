class Solution {
public:
    int word_ladder(string s,string d,unordered_set<string> words){
        queue<pair<string,int>> q;
        q.push({s,1});
        string curr; int steps;
        while(!q.empty()){
            auto [curr,steps]=q.front(); 
            q.pop();
            
            for(int i=0;i<curr.size();i++){
                string temp=curr;
                for(int j='a';j<='z';j++){
                    temp[i]=j;
                    if(temp==d){return steps+1;}
                    
                    if(words.find(temp)!=words.end()){
                        q.push({temp,steps+1});
                        words.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()){
            return 0;
        }
        unordered_set<string> words;
        for(auto x:wordList){words.insert(x);}
        
        return word_ladder(beginWord,endWord,words);
    }
};