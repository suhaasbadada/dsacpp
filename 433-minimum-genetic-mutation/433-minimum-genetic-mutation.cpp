class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string,int>> q;
        unordered_set<string> banks(bank.begin(),bank.end());
        set<char> genes={'A','C','G','T'};
        q.push({start,0});
        
        while(!q.empty()){
            string cs=q.front().first;
            int steps=q.front().second;
            q.pop();
            
            if(cs==end){return steps;}
            banks.erase(cs);
            
            for(int i=0;i<8;i++){
                string temp=cs;
                for(auto x:genes){
                    temp[i]=x;
                    if(banks.find(temp)!=banks.end()){
                        q.push({temp,steps+1});
                    }
                }
            }
        }

        return -1;
    }
};