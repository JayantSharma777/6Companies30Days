// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

string decimalToBinary(int n)
{
    string s = bitset<64> (n).to_string();
     
    const auto loc1 = s.find('1');
     
    if(loc1 != string::npos)
        return s.substr(loc1);
     
    return "0";
}
vector<string> generate(int n)
{
	vector<string> s;
	for(int i=1;i<=n;i++)
	{
	    s.push_back(decimalToBinary(i));
	}
	return s;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
