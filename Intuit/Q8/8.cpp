class Solution {
public:
     int dp[501][501];
    int dp_fact[501];
    int fact(int n)
    {
        if(dp_fact[n]!=-1)
            return dp_fact[n];
        if (n <= 1)
            return dp_fact[n]=1;
        
        return dp_fact[n]=n * fact(n - 1);
    }

    int nPr(int i, int j)
    {
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=fact(i) / fact(i - j);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        for(int i=0;i<501;i++)
        {
            dp_fact[i]=-1;
            for(int j=0;j<5;j++)
            {
                dp[i][j]=-1;
            }
        }
        
        int n=points.size();
        if(n<3)
            return 0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<double,int> map1;
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    double dist=sqrt(pow((points[i][0]-points[j][0]),2)+pow((points[i][1]-points[j][1]),2));
                    // cout<<i<<" "<<j<<" "<<dist<<endl;
                    map1[dist]++;
                }
            }
            // cout<<"in map"<<endl;
            for(auto i:map1)
            {
                if(i.second>1)
                {
                    
                    // cout<<i.first<<" "<<i.second<<endl;
                    sum+=nPr(i.second,2);
                }
            }
            // cout<<points[i][0]<<" "<<points[i][1]<<" "<<sum<<endl;
            map1.clear();
        }
        return sum;
        
    }
};
