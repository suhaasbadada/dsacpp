// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    bool isTriangle(int a,int b,int c){
        return (a+b>c && a+c>b && b+c>a);
    }
    public:
    vector<int> canMakeTriangle(vector<int> A, int N){
        vector<int> rez;
        int k=3;
        int i=0,j=0;
        vector<int> sides;
        while(j<N){
            sides.push_back(A[j]);
            if(j-i+1 < k){j++;}
            else if(j-i+1==k){
                if(isTriangle(sides[sides.size()-1],sides[sides.size()-2],sides[sides.size()-3])){
                    rez.push_back(1);
                }else{
                    rez.push_back(0);
                }
                i++;
                j++;
            }
        }
        return rez;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends