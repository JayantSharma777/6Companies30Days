// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
  void PrintStack(stack<char> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
 
    char x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    PrintStack(s);
 
    // Print the stack element starting
    // from the bottom
    cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}
    string decodedString(string s){
        
        stack<char> st;
        // string res="";
        // string rt="";
        for(int i=0;i<s.length();i++)
        {
            // cout<<"in a"<<endl;
            if(s[i]!=']')
            {
                st.push(s[i]);
            }
            else
            {
                // cout<<"here"<<endl;
                // st.pop();
                string res="";
                // res+="";
                while(st.top()!='[')
                {
                    res+=st.top();
                    st.pop();
                }
                st.pop();
                // int l=st.top()-'0';
                string l="";
                char le=st.top();
                // cout<<le<<endl;
                int x=le-'0';
                // cout<<x<<endl;
                while(true)
                {
                    // cout<<le<<" ";
                    
                    l+=le;
                    st.pop();
                    if(!st.empty())
                    {
                    le=st.top();
                    x=le-'0';
                    if(x>9 || x<0)
                    {
                        break;
                    }
                    }
                    else
                    break;
                }
                // cout<<endl;
                reverse(l.begin(), l.end());
                int len=stoi(l);
                string ans="";
                for(int j=0;j<len;j++)
                {
                    ans+=res;
                }
                for(int j=ans.length()-1;j>=0;j--)
                    st.push(ans[j]);
            }
            // PrintStack(st);
            // cout<<endl;
            // cout<<rt<<endl;
            // cout<<"yo"<<endl;
            
        }
        string rt="";
        while(!st.empty())
        {
            rt+=st.top();
            st.pop();
        }
        reverse(rt.begin(), rt.end());
        return rt;
        // return "";
        
    }
    
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
