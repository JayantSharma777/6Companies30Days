// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++

ull dp[10000000];
class Solution{
public:	
	ull getNthUglyNo(ull n)
	{
	    int i=0,j=0,k=0;
	    vector<ull> arr;
	    arr.push_back(1);
	    for(int s=2;s<=(n);s++)
	    {
	        ull a=arr[i]*2;
	        ull b=arr[j]*3;
	        ull c=arr[k]*5;
	        ull ans=min(a,min(b,c));
	        arr.push_back(ans);
	        
	        if(ans==a)
	        {
	            i++;
	        }
	        if(ans==b)
	        {
	            j++;
	        }
	        if(ans==c)
	        {
	            k++;
	        }
	       // cout<<ans<<" ";
	    }
	   // cout<<endl;
	    return arr[n-1];
	    
//		
}
};
	
	 


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
