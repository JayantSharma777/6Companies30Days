// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > arr, int r, int c) 
    {
        vector<int> res;
        int endj=c;
        int endi=r;
        int starti=0;
        int startj=0;
        while(starti<endi && startj<endj)
        {
           if(starti!=endi)
           {
        for(int i=startj;i<endj;i++)
        {
            // cout<<arr[starti][i]<<" ";
            res.push_back(arr[starti][i]);
        }
        starti++;
           }
        if(startj!=endj)
        {
        for(int i=starti;i<endi;i++)
        {
            // cout<<arr[i][endj-1]<<" ";
            res.push_back(arr[i][endj-1]);
        }
        endj--;
        }
        if((endi)!=starti)
        {
         for(int i=endj-1;i>=startj;i--)
        {
            // cout<<"yo"<<endl;
            // cout<<arr[endi-1][i]<<" ";
            res.push_back(arr[endi-1][i]);
        }
        endi--;
        }
        if((endj)!=startj)
        {
         for(int i=endi-1;i>=starti;i--)
        {
            // cout<<arr[i][startj]<<" ";
            res.push_back(arr[i][startj]);
        }
        startj++;
        }
        }
        return res;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
