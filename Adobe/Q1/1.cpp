#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int start=0;
        int end=1;
        vector<int> res;
        if(n>1)
        {
        int sum=arr[start]+arr[end];
        while(sum!=s && end<=(n-1) )
        {
            if(sum<s)
            {
                end++;
                sum+=arr[end];
            }
            if(sum>s)
            {
                sum-=arr[start];
                start++;
            }
        }
        if(sum==s)
        {
            res.push_back(++start);
            res.push_back(++end);
            return res;
        }
        else
        {
            res.push_back(-1);
            return res;
        }
        
        }
        else
        {
          if(arr[0]==s)
          {
              vector<int> res={1,1};
              return res;
          
        }
        else
        {
            vector<int> res={-1};
              return res;
        }
    }
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
