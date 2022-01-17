class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int b=0;
        vector<int> ctr;
        int start=-1;
        for(int i=0;i<arr.size()-1;i++)
        {
            if(arr[i]<arr[i+1])
            {
                start=i;
                break;
            }
        }
        if(start==-1)
            return 0;
        for(int i=start;i<arr.size()-1;i++)
        {   
            if(i==start)
            {
                b=1;
                ctr.push_back(i);
            }
            else
            {
            if(arr[i]==arr[i+1] && b==0)
            {
                ctr.push_back(i);
                b=-1;
            }
            if(arr[i]==arr[i+1] && b==-2)
            {
                // ctr.push_back(i);
                b=-1;
            }
            if(arr[i]==arr[i+1] && b==1)
            {
                ctr.push_back(-1);
                b=-1;
            }
            if((i-1)>=0 && arr[i] <arr[i-1] && arr[i]<arr[i+1] && (b==0 ))
            {
                ctr.push_back(i);
                ctr.push_back(i);
                b=1;
            }
            if((i-1)>=0 && arr[i] <arr[i-1] && arr[i]<arr[i+1] && (b==-2 ))
            {
                ctr.push_back(i);
                b=1;
            }
            if((i-1)>=0 && arr[i] == arr[i-1] && arr[i]<arr[i+1] && b==-1)
            {
                ctr.push_back(i);
                b=1;
            }
            if((i-1)>=0 && arr[i] == arr[i-1] && arr[i]>arr[i+1] && b==-1)
            {
               b=-2;
            }
            
            if(arr[i]>arr[i+1] && b==1)
            {
                b=0;
            }
            }
            cout<<b<<" ";
        }
        
        cout<<endl;
        if(b==0)
        {
            ctr.push_back(arr.size()-1);
        }
        int ans=0;
         for(int i=0;i<ctr.size();i++)
        {
            cout<<ctr[i]<<" ";
        }
        for(int i=1;i<ctr.size();i+=2)
        {
            if(ctr[i]!=-1)
            {
                ans=max(ans,(1+ctr[i]-ctr[i-1]));
            }
        }
        // cout<<endl;
        return ans;
        
    }
};
