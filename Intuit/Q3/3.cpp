// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    for(int i=1;i<=6;i++)
    {
        int ctr=0;
        string prev="";
        string prev1="";
        int j=0;
        int counter=0;
        int ans=0;
        while(j<str.length())
        {
            if(ctr==0)
            {
                if(j==0)
                {
                    string s=str.substr(j,i);
                    int num=stoi(s);
                    // cout<<num;
                    num+=1;
                    prev=to_string(num);
                    num+=1;
                    prev1=to_string(num);
                    j+=i;
                }
                else
                {
                string s=str.substr(j,prev.length());
                string s2="";
                if(prev.length()==prev1.length())
                {
                    s2=s;
                }
                else
                {
                    s2=str.substr(j,prev.length()+1);
                }
                if(s==prev)
                {
                    int num=stoi(s);
                    // cout<<num;
                    j+=prev.length();
                    num+=1;
                    prev=to_string(num);
                    num+=1;
                    prev1=to_string(num);
                    
                }
                else if(s2==prev1)
                {
                    int num=stoi(s2);
                    ans=stoi(prev);
                    // cout<<prev<<endl;
                    // cout<<ans<<endl;
                    num+=1;
                    j+=prev1.length();
                    prev=to_string(num);
                    prev1=to_string(num);
                    ctr=1;
                    // cout<<j<<endl;
                }
                else
                {
                    break;
                }
                }
            }
            else
            {
                // cout<<"yay"<<endl;
                string s=str.substr(j,prev.length());
                if(s==prev)
                {
                    int num=stoi(s);
                    num+=1;
                    j+=prev.length();
                    prev=to_string(num);
                    
                }
                else
                {
                    counter=1;
                    break;
                }
                
            }
        }
        if(ctr==1 && counter==0)
        {
            // cout<<ans<<" yo"<<endl;
            return ans;
        }
    }
    return -1;
    
}
