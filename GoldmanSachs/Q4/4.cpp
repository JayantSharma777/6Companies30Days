// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  string res="";
  char  prev=src[0];
  if(src.length()==1)
  {
      res=src+"1";
      return res;
  }
  int count=1;
  for(int i=1;i<src.length();i++)
  {
      if(src[i]!=prev)
      {
          res+=prev;
          res+=to_string(count);
          count=1;
          prev=src[i];
      }
      else
      {
          count++;
      }
  }
  res+=prev;
  res+=to_string(count);
  return res;
//   cout<<res<<endl;
  
}     
 

