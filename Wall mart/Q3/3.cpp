class Solution {
public:
    bool winnerOfGame(string s) {
        int n=s.length();
        int count0=0;
        int count1=0;
        char prev=s[0];
        int count=1;
        // if(char=='A')
        //     count++;
        // else
        //     count1++;
        for(int i=1;i<n;i++)
        {
            
            if(s[i]==prev)
            {
                count++;
            }
            else
            {
                if(s[i]=='A')
                {
                 if(count>2)
                     count1+=count-2;
                 count=1;
                    prev='A';
                }
                else
                {
                    if(count>2)
                        count0+=count-2;
                    count=1;
                    prev='B';
                }
            }
        }
        // cout<<count0<<" "<<count1<<endl;
        if(count>2)
        {
            // cout<<count<<endl;
            if(s[n-1]=='B')
                count1+=count-2;
            else
                count0+=count-2;
        }
        // cout<<count0<<" "<<count1<<endl;
        if(count0>count1)
            return true;
        else
            return false;
    }
};
