class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int n=arr.size();
        int i=0,j=0;
        int sum=0;
        int res=1e9;
        
        while(i!=n)
        {
            if(sum<target)
            {
                sum+=arr[i];
                i++;
            }
            else
            {   
                // cout<<j<<" "<<i<<endl;
                res=min(res,i-j-1);
                sum-=arr[j];
                j++;
            }
             // cout<<sum<<endl;
        }
        
        if(sum>=target)
        {
            while(j<=i)
            {
                if(sum>=target)
                {
                res=min(res,i-j-1);
                sum-=arr[j];
                j++; 
                }
                else
                    break;
            }
        }
        if(res==1e9)
        {
            return 0;
        }
        return res+1;
    }
};
