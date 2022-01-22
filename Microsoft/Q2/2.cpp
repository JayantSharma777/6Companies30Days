// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isCyclicUtil(bool visited[],bool *recstack,vector<int> adj[],int i)
    {
        // cout<<i<<endl;
        if(!visited[i])
        {
            visited[i]=true;
            recstack[i]=true;
            bool flag=false;
            for(int j=0;j<adj[i].size();j++)
            {
                if(!visited[adj[i][j]] && isCyclicUtil(visited,recstack,adj,adj[i][j]))
                    return true;
                else if(recstack[adj[i][j]])
                     return true;
            }
        }
        recstack[i]=false;
        return false;
    }
    bool isCyclic(vector<int> adj[],int n)
    {
        bool *visited = new bool[n];
    bool *recstack = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
        recstack[i] = false;
    }
    bool flag=false;
        for(int i=0;i<n;i++)
        {
                flag=isCyclicUtil(visited,recstack,adj,i);
                if(flag)
                    return true;
        }
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& arr) {
	    vector<int> adj[N];
	    for(int i=0;i<arr.size();i++)
	    {
	        adj[arr[i].first].push_back(arr[i].second);
	    }
	    bool ans=isCyclic(adj,N);
	    return !ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends
