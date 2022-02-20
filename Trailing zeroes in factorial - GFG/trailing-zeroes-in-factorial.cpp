// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int trailingZeroes(int N){
      int rez=0;
      int p5=5;
      
       while(N/p5){
          rez+=(N/p5);
          p5*=5;
       }
      
      return rez;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends