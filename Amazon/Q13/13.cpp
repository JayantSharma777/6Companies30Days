class Solution {
public:
    int arr[10][10];
    void calcans(vector<vector<int>>& grid,int i,int j,char prev,int time)
    {
             
            if(time<arr[i][j])
                arr[i][j]=time;
            if(prev!='u' && (i+1)<grid.size() && grid[i+1][j]==1)
            {
                // grid[i+1][j]=2;
                if((time+1)<arr[i+1][j])
                    calcans(grid,i+1,j,'d',time+1);
            }
            if(prev!='r' && (j-1)>=0 && grid[i][j-1]==1)
            {
                // grid[i][j-1]=2;
               if((time+1)<arr[i][j-1]) 
                    calcans(grid,i,j-1,'l',time+1);
            }
            if(prev!='d' && (i-1)>=0 && grid[i-1][j]==1)
            {
                // grid[i-1][j]=2;
                if((time+1)<arr[i-1][j])
                    calcans(grid,i-1,j,'u',time+1);
            }
            if(prev!='l' && (j+1)<grid[0].size() && grid[i][j+1]==1)
            {
                // grid[i][j+1]=2;
                if((time+1)<arr[i][j+1])
                    calcans(grid,i,j+1,'r',time+1);
            }
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[i][j]=100;
            }
        }
        int starti,startj;
        // int ctr=0;
        int maxi=0;
        // vector<vector<int>> temp;
        // temp=grid;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    starti=i;
                    startj=j;
                    maxi=-1;
                    // grid=temp;
                    calcans(grid,starti,startj,'s',0);
                    // grid=temp;
                     
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<m;j++)
                        {
                            if(arr[i][j]!=100)
                                maxi=max(maxi,arr[i][j]); 
                        }
                    }
                }
            }
            
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && arr[i][j]==100)
                    return -1;
            }
        }
        
        if(maxi==-1)
            return 0;
        return maxi;
        
    }
};
