#include<iostream>
using namespace std;
struct Node
{
    int key;
    Node *left,*right;
    Node(int x)
    {
        key=x;
        left=NULL;
        right=NULL;
    }
};
bool Rsearch(Node *root,int x)
{
    if(root==NULL)
        return false;
    else if(root->key==x)           //time complexity : O(h) where h is height of bst
        return true;                //aux space complexity : O(h)
    else if(root->key<x)
        return Rsearch(root->right,x);
    else
        return Rsearch(root->left,x);
}
bool ITRsearch(Node *root,int x)
{
    while(root!=NULL)
    {
        if(root->key==x)
            return true;
        else if(root->key<x)                //time complexity: O(h) where h is height of bst
            root=root->right;               //aux space complexity: O(1)
        else
            root=root->left;
    }
    return false;
}
Node *Rinsert(Node *root,int x)
{
    if(root==NULL)
        return new Node(x);
    else if(root->key<x)        //time complexity is O(h) n aux space is O(h)
        root->right=Rinsert(root->right,x);
    else if(root->key>x)
        root->left=Rinsert(root->left,x);
    return root;
}
Node *ITRinsert(Node *root,int x)
{
    Node *temp=new Node(x);
    Node *parent=NULL,*curr=root;
    while(curr!=NULL)
    {
        parent=curr;
        if(curr->key>x)         //time complexity is O(h) n aux space is O(1)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        else 
            return root;
    }
}