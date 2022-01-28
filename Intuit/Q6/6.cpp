/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int low=0;
        int high=arr.length();
        int val[high];
        int n=high;
        for(int i=0;i<high;i++)
        {
            val[i]=-1;
        }
        int maxind=-1;
        while(low<high)
        {
            int mid=(high+low)/2;
            if(mid==(n-1))
            {
                high=n-1;
            }
            else if(mid==0)
            {
                low=0;
            }
            else
            {
            int curr,next,prev;
            
            if(val[mid]==-1)
            {
                curr=arr.get(mid);
                val[mid]=curr;
            }
            else
                curr=val[mid];
            if(val[mid+1]==-1)
            {
                next=arr.get(mid+1);
                val[mid+1]=next;
            }
            else
                next=val[mid+1];
            if(val[mid-1]==-1)
            {
                prev=arr.get(mid-1);
                val[mid-1]=prev;
            }
            else
                prev=val[mid-1];
            if(curr>prev && curr<next)
            {
                low=mid+1;
            }
            else if(curr<prev && curr>next)
            {
                high=mid;
            }
            else
            {
                maxind=mid;
                break;
            }   
            }
        }
        cout<<maxind<<endl;
        low=0;
        high=maxind;
        int ans=0;
        int ctr=0;
        while(low<high)
        {
            int mid=(high+low)/2;
             // cout<<low<<" "<<mid<<" "<<high<<endl;
            int curr;
            if(val[mid]==-1)
            { curr=arr.get(mid);
             val[mid]=curr;
            }
            else
                curr=val[mid];
            if(curr<target)
            {
                low=mid+1;
            }
            else if(curr>target)
            {
                high=mid;
            }
            else
            {
                return mid;
            }
        }
        // cout<<val[maxind]<<" yo"<<endl;
        if(val[maxind]==target)
        {
            return maxind;
        }
        low=maxind+1;
        high=arr.length();
        
        while(low<high)
        {
            int mid=(high+low)/2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            int curr;
            if(val[mid]==-1)
            { 
                curr=arr.get(mid);
                val[mid]=curr;
            }
            else
                curr=val[mid];
            if(curr<target)
            {
                high=mid;
            }
            else if(curr>target)
            {
                low=mid+1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
        
        
    }
};
