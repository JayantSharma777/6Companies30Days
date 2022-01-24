// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string str[],int n)
    {
        unordered_map<string,int> map1;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            map1[str[i]]++;
            maxi=max(maxi,map1[str[i]]);
        }
        map<string,int> map2;
        for(auto i:map1)
        {
           if(i.second==maxi)
           {
               map2[i.first]++;
           }
        }
        vector<string> res;
        auto i=map2.begin();
        res.push_back(i->first);
        res.push_back(to_string(maxi));
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends
