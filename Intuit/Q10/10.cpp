class Solution {
public:
    void dfs(vector<int> *adj,int *visited,int *diffside,int i,int count)
    {
        visited[i]=1;
        diffside[i]=count;
        for(int j=0;j<adj[i].size();j++)
        {
            if(visited[adj[i][j]]==-1)
             dfs(adj,visited,diffside,adj[i][j],count);  
        }
            
    }
    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
        int diffsize[n];
        int visited[n];
        for(int i=0;i<n;i++)
        {
            diffsize[i]=-1;
            visited[i]=-1;
        }
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>=i)
                {
                if(arr[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
        int count=1;
        diffsize[0]=count;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                dfs(adj,visited,diffsize,i,count);
                count++;
            }
        }
        return count-1;
        
    }
};
