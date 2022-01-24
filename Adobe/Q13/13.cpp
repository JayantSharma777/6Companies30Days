// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int solve(vector<int> res)
  {
      vector<int> lis;
      for(int i=0;i<res.size();i++)
      {
          auto it=lower_bound(lis.begin(),lis.end(),res[i]);
          if(it!=lis.end())
          {
              *it=res[i];
          }
          else
          {
              lis.push_back(res[i]);
          }
      }
      return lis.size();
  }
    int minInsAndDel(int arr[], int brr[], int n, int m) {
        unordered_map<int,int> s;
        for(int i=0;i<m;i++)
        {
            s[brr[i]]++;
        }
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            if(s.find(arr[i])!=s.end())
            {
                res.push_back(arr[i]);
            }
        }
        int LIS=solve(res);
        int changes=n-res.size()+(res.size()-LIS)+m-LIS;
        return changes;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends
