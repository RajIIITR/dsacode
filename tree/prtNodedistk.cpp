#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};
void printDist(Node *root,int k)
{
    if(root==NULL) return;
    if(k==0){cout<<(root->key)<<" ";}
    else
    {
        printDist(root->left,k-1);
        printDist(root->right,k-1);
    }
}
bool isCSum(Node *root)
{
    if(root==NULL)return true;
    if(root->left==NULL && root->right==NULL)
        return true;
    int sum=0;
    if(root->left!=NULL){sum+=root->left->key;}
    if(root->right!=NULL){sum+=root->right->key;}
    return(root->key==sum && isCSum(root->left)&& isCSum(root->right));
    
}
int isBalanced(Node *root)
{
    if(root==NULL)return 0;
    int lh=isBalanced(root->left);
    if(lh==-1) return -1;
    int rh=isBalanced(root->right);
    if(rh==-1)return -1;
    if(abs(lh-rh)>1)return -1;
    else return max(lh,rh)+1; 
}
int maxWidth(Node *root) //time complexity theta(n) aux space theta(n)
{
    if(root==NULL)return 0;
    queue<Node*>q;
    q.push(root);
    int res=0;
    while(q.empty()==false)
    {
        int count=q.size();
        res=max(res,count);
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
    return res;
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    printDist(root,1);
    return 0;
}