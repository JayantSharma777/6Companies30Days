// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(int *arr, int n) {
        unordered_map<int,int> map1;
        for(int i=0;i<n;i++)
        {
            map1[arr[i]]++;
        }
        vector<int> res;
        for(int i=1;i<=n;i++)
        {
            if(map1[i]==2)
            {
              res.push_back(i);  
            }
            
        }
        for(int i=1;i<=n;i++)
        {
            if(map1[i]==0)
            {
              res.push_back(i);  
            }
            
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
