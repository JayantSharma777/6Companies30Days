// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string res;
    void helper(long long int n)
    {
        // cout<<res<<endl;
        if(n<=26)
        {
            res+= n+'A'-1;
            return;
        }
        if(n==0)
            return;
        int ans=n%26;
        if(ans==0)
        {
            ans=26;
            n--;
        }
        // cout<<n<<" "<<ans<<endl;
        n=n/26;
        res+=ans+'A'-1;
        helper(n);
    }
    string colName (long long int n)
    {
        helper(n);
        
        reverse(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends
