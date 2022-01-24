// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int arr[], int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        vector<unordered_map<int,int>> map1(n);
        int maxf=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int diff=arr[i]-arr[j];
                if(map1[j].find(diff)==map1[j].end())
                {
                    map1[i][diff]=2;
                }
                else
                {
                    map1[i][diff]=map1[j][diff]+1;
                }
                maxf=max(maxf,map1[i][diff]);
            }
        }
        return maxf;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
