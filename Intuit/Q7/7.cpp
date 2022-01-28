class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
       int sum=0;
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            sum+=weights[i];
            maxi=max(maxi,weights[i]);
            
        }
        int low=maxi;
        int high=sum;
        int ans=INT_MAX;
        while(low<=high)
        {
            int mid=(high+low)/2;
            int currsum=weights[0];
            int subarrays=1;
            for(int i=1;i<n;i++)
            {
                if(currsum+weights[i]<=mid)
                {
                    currsum+=weights[i];
                }
                else
                {
                    subarrays++;
                    currsum=weights[i];
                }
            }
            if(subarrays<=days)
            {
                high=mid-1;
                ans=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
        
        
        
    }
};
