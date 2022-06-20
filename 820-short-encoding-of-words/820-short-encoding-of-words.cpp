class Solution {
public:
    bool isPrefixFromBack(string s,string t){
        if(s.size()<t.size()){return false;}
        
        int k1=s.size()-1,k2=t.size()-1,k=t.size();
        
        while(k--){
            if(s[k1]==t[k2]){
                k1--;
                k2--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool isPrefixFromFront(string s,string t){
        for(int i=0,j=0;i<s.size() && j<t.size();i++,j++){
            if(s[i]!=t[j]){
                return false;
            }
        }
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        vector<string> w;
        for(auto x:words){
            reverse(x.begin(),x.end());
            w.push_back(x);
        }
        sort(w.begin(),w.end());
        int i=w.size()-1-1;
        string k=w[w.size()-1],z=w[w.size()-1];
        while(i>=0){
            if(isPrefixFromFront(w[i],k)){
                i--;            
            }else{
                z+="#";
                z+=w[i];
                k=w[i];
            }
        }
        z+="#";
        cout<<z<<endl;
        return z.size();
    }
};