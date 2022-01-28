// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool visited[101][101];
    bool bfs(vector<vector<char> >& arr, string word,int i,int j,int index,char p)
    {
    // 	cout<<i<<" "<<j<<endl;
    	
        if(index==word.length())
        {
            return 1;
        }
       bool ans=false;
       visited[i][j]=true;
       if(i>0)
       {
           if(!visited[i-1][j] && arr[i-1][j]==word[index] && p!='d')
           {
               ans=ans+bfs(arr,word,i-1,j,index+1,'u');
           }
       }
       if(j>0)
        {
            if(!visited[i][j-1] && arr[i][j-1]==word[index] && p!='r')
           {
               ans=ans+bfs(arr,word,i,j-1,index+1,'l');
           }
            
        }
        if(i<arr.size()-1)
        {
            if(!visited[i+1][j] && arr[i+1][j]==word[index] && p!='u')
           {
               ans=ans+bfs(arr,word,i+1,j,index+1,'d');
           }
            
        }
        if(j<arr[0].size()-1)
        {
            if(!visited[i][j+1] && arr[i][j+1]==word[index] && p!='l')
           {
               ans=ans+bfs(arr,word,i,j+1,index+1,'r');
           }
            
        }
        return ans;
       
        
    }
    bool isWordExist(vector<vector<char> >& board, string word) {
        char st=word[0];
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                visited[i][j]=false;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == st)
                {
                    visited[i][j]=true;
                    bool ans=bfs(board,word,i,j,1,'-1');
                    if(ans)
                    return 1;
                    for(int i=0;i<101;i++)
			        {
			            for(int j=0;j<101;j++)
			            {
			                visited[i][j]=false;
			            }
			        }
                    
                }
                
            }
        }
        return 0;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
