// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int count=0;
        int ctr=1;
        if(str[0]=='-')
        {
            ctr=-1;
            str=str.substr(1,str.length()-1);
            // cout<<str;
        }
        for(int i=0;i<str.length();i++)
        {
            if(str[i]>='0' && str[i]<='9')
            {
                count++;
            }
        }
        if(count!=str.length())
        {
            return -1;
        }
        int x=0;
        int r=1;
        int i=count-1;
        int sum=0;
        while(i>=0)
        {
            int x=str[i]-'0';
            sum+=x*r;
            r*=10;
            i--;
        }
        return sum*ctr;
        
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends
