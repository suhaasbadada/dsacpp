// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    vector<int> rez;
    void subset_sum(vector<int> arr,int n,int sum,int i){
        if(i==n){
            rez.push_back(sum);
            return ;
        }
        subset_sum(arr,n,sum+arr[i],i+1);
        subset_sum(arr,n,sum,i+1);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        subset_sum(arr,N,0,0);
        sort(rez.begin(),rez.end());
        
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
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends