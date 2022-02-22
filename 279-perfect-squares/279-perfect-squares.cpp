class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>> q;
        q.push({n,0});
        int steps=0;
        
        while(!q.empty()){
                auto p=q.front(); q.pop();
                long long num=p.first;
                int c=p.second;
                steps=c;
                long long sqnum=sqrt(num);
                
                if(sqnum*sqnum==num){
                    return c+1; 
                }

                for(int k=sqnum;k>0;k--){
                    q.push({num-k*k,c+1});
                }
            }
        
            return steps;
        }

};