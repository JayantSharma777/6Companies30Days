// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count=0;
        int i=0,j=0;
        long long sum=1;
        while(i<n )
        {
           sum*=a[i]; 
           while(sum>=k && j<=i)
           {
               sum/=a[j];
               j++;
           }
           count+=i-j+1;
        //   cout<<count<<endl;
        i++;
        }
    return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
