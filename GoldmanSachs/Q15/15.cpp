// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> arr, int k) {
        unordered_map<int,int> map1;
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=arr[i]%k;
            if(arr[i]==0)
                arr[i]=k;
        }
        for(int i=0;i<arr.size();i++)
        {
            // cout<<arr[i]<<" ";
            map1[arr[i]]++;
        }
        // cout<<endl;
        int ctr=0;
        for(auto i:map1)
        {
            if(i.first!=k)
            {
                if(i.second!=(map1[(k-i.first)]))
                {
                    // cout<<map1[k-i.second]<<endl;
                    ctr=1;
                    break;
                }
            }
            else
            {
                if(i.second%2!=0)
                {
                    ctr=1;
                    break;
                }
            }
        }
        if(ctr==1)
        {
            return false;
        }
        return true;
        // Code here.
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
