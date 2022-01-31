class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<float,int>> adj[n];
        vector<bool> vis(n,false);
        int k=0;
        for(auto i:edges){
            adj[i[0]].push_back({succProb[k],i[1]});
            
            adj[i[1]].push_back({succProb[k],i[0]});
            k++;
        }
        
        
        
        priority_queue<pair<float,int>> pq;
        for(auto i:adj[start]){
            pq.push(i);
            
        }
        // cout<<pq.top().first<<endl;
        while(!pq.empty()){
            
            
            auto a=pq.top();
            vis[a.second]=true;
            if(a.second==end){
                return a.first;
            }
            pq.pop();
            for(auto i:adj[a.second]){
               
                if(vis[i.second]==false)
                    pq.push({a.first*i.first,i.second});
            }
            
        }
        return 0;
        
    }
};
