// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string str) { 
        map<char,int> map1;
        int n=str.length();
        if(n<4)
        return "-1";
        string s=str.substr(0,n/2);
        // cout<<s<<endl;
        int index=-1;
        int l=n/2;
        for(int i=l-1;i>0;i--)
        {
            if(s[i]<=s[i-1])
            {
                map1[s[i]]++;
            }
            else
            {
                map1[s[i]]++;
                index=i-1;
                break;
            }
        }
        if(index==-1)
        {
            return "-1";
        }
        string res=s.substr(0,index);
        // cout<<res<<endl;
        char x=s[index];
        // cout<<x<<endl;
        for(map<char,int>::iterator i=map1.begin();i!=map1.end();i++)
        {
            if(i->first > x)
            {
                res+=i->first;
                i->second=i->second-1;
                break;
            }
        }
        map1[x]++;
        for(auto i:map1)
        {
            for(int j=0;j<i.second;j++)
            {
                res+=(i.first);
            }
        }
        // cout<<res<<endl;
         if(n%2==0)
        {
            string res1=res;
            reverse(res1.begin(),res1.end());
            res=res+res1;
            return res;
        }
        string res1=res;
        res+=str[n/2];
        reverse(res1.begin(),res1.end());
        return res+res1;
        return res;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
