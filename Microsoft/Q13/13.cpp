// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    unordered_map<int,int> map1;
    void dfs(vector<int> adj[],int i)
    {
        // cout<<i<<" ";
        // if(adj[i].size()>0)
        map1[i]++;
        for(int j=0;j<adj[i].size();j++)
        {
            if(map1[adj[i][j]]==0)
            {
                dfs(adj,adj[i][j]);
            }
        }
        
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // dfs(adj,V);
        // int ans=map1.size();
        // cout<<ans<<endl;
        // map1.clear();
        vector<int> vec;
        for(int i=0;i<adj[c].size();i++)
        {
            if(adj[c][i]!=d)
            {
                vec.push_back(adj[c][i]);
            }
        }
        adj[c]=vec;
        vector<int> vec2;
        for(int i=0;i<adj[d].size();i++)
        {
            if(adj[d][i]!=c)
            {
                vec2.push_back(adj[d][i]);
            }
        }
        adj[d]=vec2;
        dfs(adj,d);
        // cout<<endl<<map1.size()<<endl;
        
        if(map1[c]>0)
            return 0;
        return 1;
        
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
