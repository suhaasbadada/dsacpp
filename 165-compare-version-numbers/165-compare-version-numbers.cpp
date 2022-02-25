class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        int vs1=version1.size(),vs2=version2.size();
        int i=0,j=0;
        
        while(i<vs1 || j<vs2){
            int v1=0,v2=0;
        
            while(i < vs1 && version1[i]!='.'){
                v1=v1*10+(version1[i]-'0');
                i++;
            }


            while(j < vs2 && version2[j]!='.'){
                v2=v2*10+(version2[j]-'0');
                j++;
            }
            cout<<v1<<" "<<v2<<endl;

            if(v1>v2){
                return 1;
            }else if(v2>v1){
                return -1;
            }
            
            i++;
            j++;
        }
        
        return 0;
        
    }
};