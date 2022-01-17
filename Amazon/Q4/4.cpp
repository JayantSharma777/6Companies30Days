// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string st="";
    char name;
    int dp[501][501];
        int kp[501][501];
    void printParenthesis(int i, int j, int n){
        if(i>j)
        return;
        
    	if (i == j){
    		st += name;
    		name++;
    		return;
    	}
    	st += '(';
    	printParenthesis(i, kp[i][j], n);
    	printParenthesis(kp[i][j] + 1, j,n);
    	st += ')';
    }
    string matrixChainOrder(int arr[], int n){
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=j)
                    dp[i][j]=0;
                    kp[i][j]=0;
            }
        }
        for(int gap=1;gap<n-1;gap++)
        {
            for(int i=1;i<n-gap;i++)
            {
               int j=i+gap;
                    int ans=0;
                    int mina=INT_MAX;
                    for(int k=i;k<j;k++)
                    {
                        int temp=dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j];
                        if(mina>temp)
                        {
                            mina=temp;
                            ans=k;
                        }
                    }
                    dp[i][j]=mina;
                    kp[i][j]=ans;
                }
            
            
        }
        name='A';
        printParenthesis(1,n-1,n);
        return st;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
