// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(pair<double,double> p1,pair<double,double> p2){
        return (p1.first/p1.second > p2.first/p2.second);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,double>> vp;
        for(int i=0;i<n;i++){
            vp.push_back({arr[i].value*1.0,arr[i].weight*1.0});
        }
        
        sort(vp.begin(),vp.end(),comp);
        
        int cw=0;
        double pick=0;
        for(auto x:vp){
            if(W>=x.second){
                pick+=x.first;
                W-=x.second;
            }else{
                double fraction=W/x.second;
                pick+=fraction*x.first;
                //  W-=(W/x.second);
                 break;
            }  
        }
        
        return pick;
    }
        
};

/*

30 -> 120
20 -> x

20/30


*/


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends