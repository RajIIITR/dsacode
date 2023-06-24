#include<iostream>
using namespace std;
class Node
{
    public:
        Node *prev;
        int data;
        Node *next;
};
class Linkedlist
{
    private:
        Node *first;
    public:
        Linkedlist(){ first=NULL;}
        Linkedlist(int A[],int n);
        ~Linkedlist();
        void Display();
        void Insert(int index, int x);
        int Delete(int index);
        int length();
};
Linkedlist::Linkedlist(int A[],int n)
{
    Node *last,*t;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    first->prev=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=first;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
Linkedlist::~Linkedlist()
{
    Node *p=first;
    while(first->next!=first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}
void Linkedlist::Display()
{
    Node *p=first;
    cout<<p->data<<" ";
    p=p->next;
    while(p!=first)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int Linkedlist::length()
{
    Node *p=first->next;
    int c=1;
    while(p!=first)
    {
        c++;
        p=p->next;
    }
    return c;
}
void Linkedlist::Insert(int index,int x)
{
    Node *t,*p=first;
    if(index<0 || index>length())
        return;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(index==0)
    {
        t->next=first;
        first->prev->next=t;
        t->prev=first->prev;
        first->prev=t;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next->prev=t;
        t->prev=p;
        p->next=t;
    }
}
int Linkedlist::Delete(int index)
{
    Node *p,*q=NULL;
    int x=-1;
    if(index<1||index>length())
        return -1;
    if(index==1)
    {
        p=first;
        first=first->next;
        first->prev=p->prev;
        p->prev->next=first;
        x=p->data;
        delete p;
    }
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        p->next->prev=q;
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}
int main()
{
    int A[]={1,2,3,4,5};
    Linkedlist l(A,5);
    cout<<l.Delete(3)<<endl;
    cout<<l.length()<<endl;
    l.Insert(0,10);
    l.Display();
    return 0;
}