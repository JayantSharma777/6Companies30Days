// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
     vector<string> res;
    int counter=0;
    int ctr=0;
    int sum=1;
    void calcstring(vector<string> x,int str_i,int count_i,string res1)
    {
//    	cout<<str_i<<" "<<count_i<<endl;
    	if(str_i>x.size() || ctr>=sum)
    	{
			return;
		}
        if(counter!=0)
        {
//        	cout<<x[str_i-1][count_i]<<endl;
        res1+=x[str_i-1][count_i];
        }
        counter=1;
//        cout<<res1<<endl;
         if(res1.size()==x.size())
        {
//        	cout<<res1<<endl;
            res.push_back(res1);
            ctr++;
            return;
        }
        if(str_i<x.size())
        {
        	int x1=str_i;
        	if(x1>=x.size())
        	{
        		x1=x.size();
			}
        for(int i=0;i<x[x1].size();i++)
        {       	
//        	cout<<"i before"<<str_i<<" "<<i<<endl;
            calcstring(x,str_i+1,i,res1);
//            cout<<"i after"<<str_i<<" "<<i<<endl;
            if(ctr>=sum) return;
        }
        return;
        }
        return;
    }
    vector<string> possibleWords(int arr[], int n)
    {
        vector<string> x;
        map<int,string> map1;
        map1[2]="abc";
        map1[3]="def";
        map1[4]="ghi";
        map1[5]="jkl";
        map1[6]="mno";
        map1[7]="pqrs";
        map1[8]="tuv";
        map1[9]="wxyz";
        for(int i=0;i<n;i++)
        {
            x.push_back(map1[arr[i]]);
            sum*=map1[arr[i]].length();
        }
//        cout<<sum<<endl;
        calcstring(x,0,0,"");
        return res;
        
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
