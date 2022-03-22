class MapSum {
public:
    map<string,int> mp;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        mp[key]=val;
    }
    bool startsWith(string a,string b){
        if(a.size()<b.size()){return false;}
        int k=b.size();
        for(int i=0;i<k;i++){
            if(a[i]!=b[i]){return false;}
        }
        return true;
    }
    int sum(string prefix) {
        int s=0;
        for(auto x:mp){
            if(startsWith(x.first,prefix)){
                s+=x.second;
            }
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */