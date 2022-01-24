// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int solve(vector<vector<int>> &dp,vector<int> arr,int s,int e)
    {
        if(s>e)
        {
            return dp[s][e]=0;
        }
        else if(s==e)
        {
            return dp[s][e]=arr[s];
        }
        else if(dp[s][e]!=-1)
        {
            return dp[s][e];
        }
        else
        {
            int l=arr[s]+min(solve(dp,arr,s+2,e),solve(dp,arr,s+1,e-1));
            int r=arr[e]+min(solve(dp,arr,s+1,e-1),solve(dp,arr,s,e-2));
            return dp[s][e]=max(l,r);
        }
    }
    int maxCoins(vector<int>&A,int n)
    {
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
	    return solve(dp,A,0,n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
