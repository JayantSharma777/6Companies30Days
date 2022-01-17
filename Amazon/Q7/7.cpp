// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string str){
		    int map1[26]={0};
		    string res="";
		    queue<int> q;
		    for(int i=0;i<str.length();i++)
		    {
		        map1[str[i]-'a']++;
		        
		        if((map1[str[i]-'a'])==1)
		        {
		            q.push(str[i]-'a');
		        }
		        while(!q.empty() && map1[q.front()]!=1)
		        {
		            q.pop();
		        }
		        if(!q.empty())
		        {
		            res+=q.front()+'a';
		        }
		        else
		        {
		            res+='#';
		        }
		       
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
