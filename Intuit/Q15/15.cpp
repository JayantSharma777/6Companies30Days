class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end());
        int low=1;
        int ans=INT_MAX;
        int ctr=0;
        int n=piles.size();
        if(n==1)
        {
            low=1;
        }
        while(low<=high)
        {
            // cout<<low<<" "<<high<<endl;
            
            int mid=(high+low)/2;
            
            int count=0;
            for(int i=0;i<n;i++)
            {
                count+=piles[i]/mid;
                if(piles[i]%mid >0)
                {
                    count++;
                }
            }
            if(count<=h)
            {
                
                ans=min(ans,mid);
                high=mid;
            }
            else if(count>h)
            {
                low=mid+1;
            }
            
            if(high==low)
                ctr++;
            if(ctr>1)
                break;
        }
        return ans;
        
    }
};
