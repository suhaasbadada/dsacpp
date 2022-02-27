#include <bits/stdc++.h>
class Solution {
public:
    int func(string w){
        map<char,int> mp;
        for(auto x:w){mp[x]++;}
        
        return mp.begin()->second;;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> rez,fq,fw;
        for(auto x:queries){ fq.push_back(func(x));}
        for(auto x:words){fw.push_back(func(x));}
        
        sort(fw.begin(),fw.end());
        int n=words.size();
        for(auto x:fq){
            vector<int>::iterator lb;
            lb=upper_bound(fw.begin(), fw.end(), x);
            int pos=lb-fw.begin();
            rez.push_back(n-pos);
        }
        return rez;
    }
};