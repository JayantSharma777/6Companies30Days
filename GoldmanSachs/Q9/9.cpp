// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        int i=1,d;
        int count=0;
        char curr;
        if(S[0]=='I')
        {
            curr='I';
            count++;
        }
        else
        {
            count++;
            curr='D';
        }
        int n=S.length();
        string res;
        for(int i=1;i<n;i++)
        {
            if(S[i]==curr)
            {
                count++;
            }
            else
            {
                res+=S[i-1];
                curr=S[i];
                string l=to_string(count);
                res+=l;
                count=1;
            }
        }
        if(S[n-1]==curr)
        {
            // count++;
            res+=S[n-1];
            string l=to_string(count);
            res+=l;
        }
        else
        {
            res+=S[n-1];
            string l=to_string(count);
            res+=l;
        }
        int l=res.length();
        string ans;
        int len=0;
        for(int i=0;i<l;i+=2)
        {
            
                char cur=res[i];
                int l1=(res[i+1])-'0';
               
                if(cur=='I')
                {
                    
                        for(int j=len+1;j<len+l1+1;j++)
                        {
                            ans+=to_string(j);
                        }
                        len=len+l1;
                        
                }
                else
                {
                    len+=l1+1;
                    int ctr=len;
                    for(int j=l1+1;j>0;j--)
                    {
                        ans+=to_string(ctr);
                        ctr--;
                    }
                    if((i+2) < l)
                    {
                        // cout<<i+2<<" y"<<endl;
                        int ch=(res[i+3])-'0';
                        ch--;
                        res[i+3]='0'+(ch);
                    }
                }
                // cout<<res<<endl;
                
        }
        if(l==2)
        {
            if(res[0]=='I')
            {
                ans+=to_string(len+1);
            }
        }
        if(l>2)
        {
             if(res[l-2]=='I')
             {
                 ans+=to_string(len+1);
             }
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
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
