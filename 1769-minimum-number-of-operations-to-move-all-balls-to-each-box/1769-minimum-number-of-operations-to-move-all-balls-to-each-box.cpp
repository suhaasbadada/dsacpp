class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> rez;
        
        for(int i=0;i<boxes.size();i++){
            int ops=0;
            for(int j=0;j<boxes.size();j++){
                if(boxes[j]=='1'){
                    ops+=abs(i-j);
                }
            }
            rez.push_back(ops);
        }
        
        return rez;
    }
};