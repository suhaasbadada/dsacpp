class StockSpanner {
public:
    vector<int> sp;
    stack<int> st;
    int i=0;
    StockSpanner() {}       
    
    int next(int price) {
        sp.push_back(price);
        
        int ans;
        
        while(!st.empty() && price>=sp[st.top()]){
            st.pop();
        }
        
        if(st.empty()){
            ans=i+1;
        }else{
            ans=(i-st.top());
        }
        
        st.push(i++);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */