class FreqStack {
public:
    struct custom{
        auto operator()(vector<int>& v1,vector<int>& v2){
            if(v1[0]==v2[0]){return v1[1]<v2[1];}
            return v1[0]<v2[0];
        }
    };
    priority_queue<vector<int>,vector<vector<int>>,custom> pq;
    unordered_map<int,int> mp;
    int i=0;
    FreqStack() {
    
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val],i++,val});
    
    }
    
    int pop() {
        auto p=pq.top();
        pq.pop();
        mp[p[2]]--;
        
        return p[2];        
    }
};
