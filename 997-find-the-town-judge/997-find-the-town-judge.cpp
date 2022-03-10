class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> incoming(n,0);
        vector<int> outgoing(n,0);
        // no outgoing edges, only incoming
        for(auto ed:trust){
        
            int u=ed[0];
            int v=ed[1];
            u--; v--;
          
            incoming[v]++;
            outgoing[u]++;
        }
        
        int judge=-1;
        
        for(int i=0;i<n;i++){
           if(incoming[i]==n-1 && outgoing[i]==0){
               judge=i+1;
               break;
           }
        }

        return judge;
    }
};