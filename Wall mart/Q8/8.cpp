// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int height(int N){
       if(N<3)
       return 1;
       if(N<6)
       return 2;
       int x=N*(-2);
       int x1=(-1+sqrt(1-(4*x)))/(2);
       return x1;
       
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}  // } Driver Code Ends
