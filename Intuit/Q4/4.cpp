// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string calc(string str,string s,int k,int i)
    {
        // cout<<str<<" "<<k<<" "<<i<<endl;
        if(k==0)
            return str;
        if(i==str.length())
            return str;
        int n=str.length();
        string res=str;
            if(str[i]!=s[i])
            {
                k--;
                // cout<<str[i]<<" "<<s[i]<<endl;
                for(int j=i+1;j<n;j++)
                {
                    
                    if(str[j]==s[i])
                    {
                        // cout<<str<<endl;
                        char st=str[j];
                        str[j]=str[i];
                        str[i]=st;
                        string ans=calc(str,s,k,i+1);
                        res=max(res,ans);
                         st=str[j];
                        str[j]=str[i];
                        str[i]=st;
                        // cout<<str<<" "<<i<<" "<<k<<endl;
                    }
                }
                return res;
            }
            else
            {
            res=calc(str,s,k,i+1);
            return res;
            }
    }
    string findMaximumNum(string str, int k)
    {
        string s=str;
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        int n=str.length();
        str=calc(str,s,k,0);
            
        
        
        return str;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends
