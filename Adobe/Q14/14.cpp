// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
           vector<pair<int,int>> arr;
           for(int i=0;i<k;i++)
           {
               for(int j=0;j<n;j++)
               {
                   arr.push_back(make_pair(KSortedArray[i][j],i));
               }
           }
           sort(arr.begin(),arr.end());
           pair<int,int> ans;
           int range=INT_MAX;
        //   int maxi=INT_MIN;
        //   int mini=INT_MAX;
           int i=0,j=0;
           unordered_map<int,int> map1;
           while(j<arr.size())
           {
               pair<int,int> x=arr[j];
               int val=arr[j].first;
               int index=arr[j].second;
               map1[index]++;
               if(map1.size()<k)
               {
                   j++;
               }
               else if(map1.size()==k)
               {
                   while(map1.size()==k)
                   {
                       int r=arr[j].first-arr[i].first+1;
                       if(r<range)
                       {
                           range=r;
                           ans=make_pair(arr[i].first,arr[j].first);
                       }
                       map1[arr[i].second]--;
                       if(map1[arr[i].second]==0)
                       {
                           map1.erase(arr[i].second);
                       }
                       i++;
                   }
                   j++;
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
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends 
