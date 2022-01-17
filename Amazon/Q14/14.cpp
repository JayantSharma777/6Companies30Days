// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  struct NODE {
    int data;
    NODE *left;
    NODE *right;
    NODE *parent;
    

    NODE(int val) {
        data = val;
        left = right = parent = NULL;
    }
};
NODE* createtree(Node* temp,NODE* prev)
{
    if(temp==NULL)
    return NULL;
    NODE *x=new NODE(temp->data);
    x->parent=prev;
    x->left=createtree(temp->left,x);
    x->right=createtree(temp->right,x);
    return x;
    
}
NODE* findnode(NODE* root,int target)
{
    if(root==NULL)
        return NULL;
    if(root->data==target)
    {
        return root;
    }
    else
    {
        NODE *l=findnode(root->left,target);
        NODE *r=findnode(root->right,target);
        if(l==NULL && r==NULL)
            return NULL;
        if(l!=NULL)
            return l;
        else
            return r;
    }
}
int getcount(NODE *temp,NODE *prev)
{
    
    if(temp==NULL)
    {
        return 0;
    }
    // cout<<temp->data<<endl;
    int max1=0,max2=0,max3=0;
    if(temp->parent!=NULL && prev!=temp->parent )
    {
        max1=1+getcount(temp->parent,temp);
    }
    if(temp->left!=NULL && temp->left!=prev)
    {
        max2=1+getcount(temp->left,temp);
    }
    if(temp->right!=NULL && temp->right!=prev)
    {
        max3=1+getcount(temp->right,temp);
    }
    return (max(max1,max(max2,max3)));
}
void printnode(NODE* root)
{
    if(root!=NULL)
    {
    cout<<root->data<<" ";
    printnode(root->left);
    printnode(root->right);
    }
}
    int minTime(Node* root, int target) 
    {
        NODE *Root=createtree(root,NULL);
        // printnode(Root);
        // cout<<endl;
        NODE *get=findnode(Root,target);
        // cout<<get->data<<endl;
        int ans=getcount(get,NULL);
        // cout<<ans<<endl;
       return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends
