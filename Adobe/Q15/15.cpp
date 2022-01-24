#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	string s;
	string s1;
	cin>>s>>s1;
	int l=s.length();
	vector<int> res;
	string temp="";
	for(int i=0;i<l;i++)
	{
		if(s[i]!='.')
		{
			temp+=s[i];
		}
		else
		{
			int num=stoi(temp);
			res.push_back(num);
			temp="";	
		}
	}
	
	res.push_back(stoi(temp));
	vector<int> res1;
	temp="";
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]!='.')
		{
			temp+=s1[i];
		}
		else
		{
			int num=stoi(temp);
			res1.push_back(num);	
			temp="";
		}
	}
	res1.push_back(stoi(temp));
	int len1=res.size();
	int len2=res.size();
	int len=min(len1,len2);
	for(int i=0;i<len;i++)
	{
	    if(res[i]<res1[i])
	    {
	        cout<<s1<<endl;
	        break;
	    }
	    else if(res[i]>res1[i])
	    {
	        cout<<s<<endl;
	        break;
	    }
	}
	

}


