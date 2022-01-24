// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string> res;
    void makestring(string s,int fi,int ci,int n)
    {
        if(fi==n && ci==n)
        {
            // cout<<s<<endl;
            res.push_back(s);
            return;
        }
        string s1=s;
        string s2=s;
        if(fi<n)
        {
            s1+='(';
            makestring(s1,fi+1,ci,n);
        }
        if(ci<n && ci<fi)
        {
            s2+=')';
            makestring(s2,fi,ci+1,n);
        }
        
    }
    vector<string> AllParenthesis(int n) 
    {
        makestring("",0,0,n);
        unordered_map<string,int>map1;
        for(int i=0;i<res.size();i++)
        {
            map1[res[i]]++;
            
        }
        // cout<<map1.size()<<endl;
        vector<string> ans;
        for(unordered_map<string,int>::iterator i=map1.begin();i!=map1.end();i++)
        {
           ans.push_back(i->first); 
        }
        return ans;
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
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends
