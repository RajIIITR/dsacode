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
int getMax(Node *root)
{
    if(root==NULL)
        return INT_MIN;
    else    
        return max(root->key,max(getMax(root->left),getMax(root->right)));
}
int maxlevel=0;
void Printleftrec(Node *root,int level)
{
    if(root==NULL)
        return;
    if(maxlevel<level)
    {
        cout<<(root->key)<<" ";
        maxlevel=level;
    }
    Printleftrec(root->left,level+1);
    Printleftrec(root->right,level+1); 
}
void Printleftitr(Node *root)
{
    if(root==NULL)return;
    queue<Node*>q;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(i==0)
                cout<<(curr->key)<<" ";
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
    }
}
void printleftview(Node *root)
{
    Printleftrec(root,1);
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    //cout<<getMax(root);
    return 0;
}