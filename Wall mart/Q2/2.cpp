class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& arr,int s,int e)
    {
        if(s>e)
        {
            return dp[s][e]=0;
        }
        else if(s==e)
        {
            return dp[s][e]=arr[s];
        }
        else if(dp[s][e]!=-1)
        {
            return dp[s][e];
        }
        else
        {
            int l=arr[s]+min(solve(arr,s+2,e),solve(arr,s+1,e-1));
            int r=arr[e]+min(solve(arr,s+1,e-1),solve(arr,s,e-2));
            return dp[s][e]=max(l,r);
        }
    }
    bool stoneGame(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp;
        for(int i=0;i<n;i++)
        {
            vector<int> res;
            for(int j=0;j<n;j++)
            {
                res.push_back(-1);
            }
            dp.push_back(res);
        }
	    int ans=solve(arr,0,n-1);
        int sum=0;
        // return false;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        int ans1=sum-ans;
        if(ans<ans1)
            return true;
        else
            return false;
        
    }
};
