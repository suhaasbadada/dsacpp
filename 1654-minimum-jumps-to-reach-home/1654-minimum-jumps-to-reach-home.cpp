class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {

        unordered_set<int> v;
        queue<pair<int,int>> q; 
        for(int i = 0 ; i< forbidden.size() ; i++){
            v.insert(forbidden[i]) ;
        }
        q.push(make_pair(0,0)) ;
        int ans = 0;
        while(!q.empty()){
            int size = q.size() ;
            while(size--){
                auto curr = q.front() ;
                q.pop() ;
                int num = curr.first;
                if(num == x){
                    return ans;
                }
               
                if(v.count(num) == 1){
                    continue;
                } 
                v.insert(num);
                if(curr.second == 0){
                    int step = num - b;
                    if(step >= 0){
                        q.push(make_pair(step,1));
                    }
                }
                int step = num+a;
                if(step <= 2000+a+b){
                    q.push(make_pair(step,0));
                    
                }
            }
            ans++;
        }
        return -1;

    }
};