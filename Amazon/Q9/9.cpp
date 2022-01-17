// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // int ctr=0;
        for(int i=0;i<9;i++)
        {
            int map1[10]={0};
            for(int j=0;j<9;j++)
            {
                if(map1[mat[i][j]]>0)
                {
                    return 0;
                }
                if(mat[i][j]!=0)
                 map1[mat[i][j]]++;
            }
            int map2[10]={0};
            for(int j=0;j<9;j++)
            {
                if(map2[mat[j][i]]>0)
                {
                    
                    // cout<<j<<" "<<i<<endl;
                    return 0;
                }
                if(mat[j][i]!=0)
                  map2[mat[j][i]]++;
            }
           
        }
        int i=0;
        int j=0;
        while(i<9 && j<9)
        {
            int map2[10]={0};
            for(int q=i;q<i+3;q++)
            {
                for(int r=j;r<j+3;r++)
                {
                    // cout<<q<<" "<<r<<endl;
                    
                if(map2[mat[q][r]]>0)
                {
                    return 0;
                }
                if(mat[q][r]!=0)
                  map2[mat[q][r]]++;
                }
            }
            j+=3;
            if(j==9)
            {
                j=0;
                i+=3;
            }
        }
        return 1;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
