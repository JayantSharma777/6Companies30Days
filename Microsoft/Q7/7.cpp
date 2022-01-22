// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int count=0;
    int maxcount=0;
      void calcgrid(vector<vector<bool> >& visited,vector<vector<int> >& grid,int i,int j)
    {
//    	cout<<i<<" "<<j<<endl;
        visited[i][j]=true;
        count++;
        int n=grid.size();
        int m=grid[0].size();
        if((i-1)>=0 && grid[i-1][j] && !visited[i-1][j])
        {
            calcgrid(visited,grid,i-1,j);
            
        }
         if((j-1)>=0 && grid[i][j-1] && !visited[i][j-1])
        {
            calcgrid(visited,grid,i,j-1);
            
        }
         if((i+1)<n && grid[i+1][j] && !visited[i+1][j])
        {
            calcgrid(visited,grid,i+1,j);
            
        }
         if((j+1)<m && grid[i][j+1] && !visited[i][j+1])
        {
            calcgrid(visited,grid,i,j+1);
            
        }
        if((i-1)>=0 && (j-1)>=0 && grid[i-1][j-1] && !visited[i-1][j-1])
        {
            calcgrid(visited,grid,i-1,j-1);
            
        }
         if((i-1)>=0 && (j+1)<m && grid[i-1][j+1] && !visited[i-1][j+1])
        {
            calcgrid(visited,grid,i-1,j+1);
            
        }
         if((i+1)<n && (j-1)>=0 && grid[i+1][j-1] && !visited[i+1][j-1])
        {
            calcgrid(visited,grid,i+1,j-1);
            
        }
         if((i+1)<n && (j+1)<m && grid[i+1][j+1] && !visited[i+1][j+1])
        {
            calcgrid(visited,grid,i+1,j+1);
        }
        maxcount=max(count,maxcount);
    }
    int findMaxArea(vector<vector<int> >& grid) {
        vector<vector<int> > ones;
        vector<vector<bool> > visited;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {vector<bool> x1;
            for(int j=0;j<m;j++)
            {
            	x1.push_back(false);
                if(grid[i][j])
                {
                    vector<int> ans;
                    ans.push_back(i);
                    ans.push_back(j);
                    ones.push_back(ans);
                }
            }
            visited.push_back(x1);
        }
//        cout<<ones[0].size()<<endl;

        for(int i=0;i<ones.size();i++)
        {
        	int x=ones[i][0];
        	int y=ones[i][1];
//        	cout<<x<<" "<<y<<endl;
            if(!visited[x][y])
            {
                count=0;
//                cout<<count<<endl;
                calcgrid(visited,grid,ones[i][0],ones[i][1]);
            }
        }
        return maxcount;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
