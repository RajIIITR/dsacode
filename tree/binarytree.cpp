// n=no. of node h=height of tree w=max width of tree
#include<iostream>
#include<queue>
#include<stack>
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
void inorder(Node *root) //time complextiy:O(n) aux space:O(h)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<(root->key)<<" ";
        inorder(root->right);
    }
}
void preorder(Node *root) //time complextiy:O(n) aux space:O(h)
{
    if(root!=NULL)
    {
        cout<<(root->key)<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node *root) //time complextiy:O(n) aux space:O(h)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<(root->key)<<" ";
    }
}
int height(Node *root)// time complexity: O(n) aux space: O(h)
{
    if(root==NULL)
        return 0;
    else    
        return max(height(root->left),height(root->right))+1;
}
void PrintLVL(Node *root)// time complexity: theta(n) aux space: theta(w)
{
    if(root==NULL) return;
    queue<Node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        Node *curr=q.front();
        q.pop();
        cout<<(curr->key)<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);
    }
}
void PrintLVLOrderLine(Node *root)//time complexity: O(n) aux space:theta(n)
{
    if(root==NULL)return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.size()>1)
    {
        Node *curr=q.front();
        q.pop();
        if(curr==NULL)
        {
            cout<<"\n";
            q.push(NULL);
            continue;
        }
        cout<<(curr->key)<<" ";
        if(curr->left!=NULL) q.push(curr->left);
        if(curr->right!=NULL) q.push(curr->right);
    }
}
void PrintLVLOrder(Node *root)
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
            cout<<(curr->key)<<" ";
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        cout<<endl;
    }
}
void PrintSpiral(Node *root)
{
    if(root==NULL)return;
    queue<Node*>q;
    stack<int>s;
    bool reverse=false;
    q.push(root);
    while(q.empty()==false)
    {
        int count=q.size();
        for(int i=0;i<count;i++)
        {
            Node *curr=q.front();
            q.pop();
            if(reverse)
                s.push(curr->key);
            else    
                cout<<curr->key<<" ";
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
        }
        if(reverse)
        {
            while(s.empty()==false)
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        reverse=!reverse;
        cout<<endl;
    }
}
int main()
{
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    //inorder(root);
    //cout<<endl<<height(root)<<endl;
    PrintLVLOrder(root);
    return 0;
}