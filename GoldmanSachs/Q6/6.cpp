class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int count=0;
        int ctr=1;
        string res="";
        for(int i=0;i<min(str1.length(),str2.length());i++)
        {
            if(str1[i]==str2[i])
            {
                count++;
                res+=str1[i];
            }
            else
            {
                ctr=0;
                break;
            }
        }
        if(ctr==0)
        {
            return "";
        }
        else
        {
            int l=max(str1.length(),str2.length());
            int n=res.length();
            int rem=l-n;
            if(rem==0)
                return res;
            if(n%2!=0)
            {
                if(rem%n!=0)
                {
                    int ans=__gcd(rem,n);
                    if(ans==1)
                        return "";
                    string ch=str1.substr(0,ans);
                    cout<<ch<<endl;
                    int j=0;
                    bool check=true;
                    for(int i=0;i<str1.length();i++)
                    {
                        if(j==ans)
                            j=0;
                        if(str1[i]!=ch[j])
                        {
                            check=false;
                            break;
                        }
                        j++;
                    }
                    if(!check)
                        return "";
                    j=0;
                    for(int i=0;i<str2.length();i++)
                    {
                        if(j==ans)
                            j=0;
                        if(str2[i]!=ch[j])
                        {
                            check=false;
                            break;
                        }
                        j++;
                    }
                    if(!check)
                        return "";
                    return ch; 
                }
                else
                {
                    string ch=str1.substr(0,n);
                    int j=0;
                    bool check=true;
                    for(int i=0;i<str1.length();i++)
                    {
                        if(j==n)
                            j=0;
                        if(str1[i]!=ch[j])
                        {
                            check=false;
                            break;
                        }
                        j++;
                    }
                    if(!check)
                        return "";
                    j=0;
                    for(int i=0;i<str2.length();i++)
                    {
                        if(j==n)
                            j=0;
                        if(str2[i]!=ch[j])
                        {
                            check=false;
                            break;
                        }
                        j++;
                    }
                    if(!check)
                        return "";
                    return ch;
                    
                }
            }
            else
            {
                    int ans=__gcd(rem,n);
                    string ch=str1.substr(0,ans);
                    cout<<ch<<endl;
                    int j=0;
                    bool check=true;
                    for(int i=0;i<str1.length();i++)
                    {
                        if(j==ans)
                            j=0;
                        if(str1[i]!=ch[j])
                        {
                            check=false;
                            break;
                        }
                        j++;
                    }
                    if(!check)
                        return "";
                    j=0;
                    for(int i=0;i<str2.length();i++)
                    {
                        if(j==ans)
                            j=0;
                        if(str2[i]!=ch[j])
                        {
                            check=false;
                            break;
                        }
                        j++;
                    }
                    if(!check)
                        return "";
                    return ch;
                
            }
        // return "";
        }
    }
};
