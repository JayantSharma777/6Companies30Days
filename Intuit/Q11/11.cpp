/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(vector<vector<int>>&grid,int lowi,int lowj,int highi,int highj)
    {
        if(lowi <highi && lowj<highj)
        {
        
        int count0=0;
        int count1=0;
        for(int i=lowi;i<highi;i++)
        {
            for(int j=lowj;j<highj;j++)
            {
                if(grid[i][j]==0)
                    count0++;
                else
                    count1++;
            }
        }
        if(count0>0 && count1==0)
        {
            Node *root=new Node(false,true);
           
            return root;
        }
        else if(count1>0 && count0==0)
        {
            Node *root=new Node(true,true);
            return root;
        }
        else
        {
            Node *root=new Node(true,false);
            int midi=(lowi+highi)/2;
            int midj=(lowj+highj)/2;
            root->topLeft=solve(grid,lowi,lowj,midi,midj);
            root->topRight=solve(grid,lowi,midj,midi,highj);
            root->bottomLeft=solve(grid,midi,lowj,highi,midj);
            root->bottomRight=solve(grid,midi,midj,highi,highj);
            return root;
        }
           
        }
        else
        {
            Node *root=NULL;
            return NULL;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        Node* x=solve(grid,0,0,grid.size(),grid.size());
        return x;
    }
};
