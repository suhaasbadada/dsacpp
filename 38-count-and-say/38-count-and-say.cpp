class Solution {
public:
    string countAndSay(int n) {
        string rez="1";
        n--;
        while(n--){
            int k=rez.size();
            int i=0,count=1;
            string temp="";
            while(i<k-1){
                if(rez[i]==rez[i+1]){
                    count++;
                    i++;
                }else{
                    temp+=to_string(count);
                    temp+=rez[i];
                    count=1;
                    i++;
                }
            }
            temp+=to_string(count);
            temp+=rez[i];
            // cout<<temp<<endl;
            rez=temp;
        }cout<<endl;
        return rez;
    }
};