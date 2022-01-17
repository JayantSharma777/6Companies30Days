// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int arr[]) {
        
        int dp[k+1][n];
        for(int i=0;i<n;i++)
        {
            dp[0][i]=0;
        }
        for(int i=0;i<k+1;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i][j-1];
                
                int max=dp[i][j];
                for(int k=0;k<j;k++)
                {
                    int ans=arr[j]-arr[k];
                    if((dp[i-1][k]+ans)>max)
                    {
                        max=dp[i-1][k]+ans;
                    }
                }
                dp[i][j]=max;
            }
        }
        return dp[k][n-1];
         
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
