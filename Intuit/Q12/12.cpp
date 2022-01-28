class Solution {
public:
    bool isCyclicUtil(vector<int> adj[],int v, bool visited[], bool *recStack)
    {
        if(visited[v] == false)
        {
            // Mark the current node as visited and part of recursion stack
            visited[v] = true;
            recStack[v] = true;

            // Recur for all the vertices adjacent to this vertex
            vector<int>::iterator i;
            for(i = adj[v].begin(); i != adj[v].end(); ++i)
            {
                if ( !visited[*i] && isCyclicUtil(adj,*i, visited, recStack) )
                    return true;
                else if (recStack[*i])
                    return true;
            }

        }
        recStack[v] = false;  // remove the vertex from recursion stack
        return false;
    }
    bool isCyclic(vector<int> adj[],int V)
    {
        // Mark all the vertices as not visited and not part of recursion
        // stack
        bool *visited = new bool[V];
        bool *recStack = new bool[V];
        for(int i = 0; i < V; i++)
        {
            visited[i] = false;
            recStack[i] = false;
        }

        // Call the recursive helper function to detect cycle in different
        // DFS trees
        for(int i = 0; i < V; i++)
            if (isCyclicUtil(adj,i, visited, recStack))
                return true;

        return false;
    }
    void dfs(vector<int> adj[],vector<int>& visited,int i,stack<int>& s)
    {
        visited[i]=true;
        for(int j=0;j<adj[i].size();j++)
        {
            if(visited[adj[i][j]]==-1)
            {
                dfs(adj,visited,adj[i][j],s);
            }
        }
        s.push(i);
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        if(pre.size()==0)
        {
            vector<int>res;
            for(int i=0;i<n;i++)
            {
                res.push_back(i);
            }
            return res;
        }
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][0]].push_back(pre[i][1]);
        }
        vector<int> res;
        stack<int> s;
        vector<int> visited;
        bool cycle=isCyclic(adj,n);
        if(cycle)
        {
            res.clear();
            return res;
        }
        for(int i=0;i<n;i++)
        {
            visited.push_back(-1);
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i]==-1)
            {
                dfs(adj,visited,i,s); 
            }
        }
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
