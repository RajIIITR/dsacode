#include<iostream>
using namespace std;
struct deque
{
    int size,cap;
    int *arr;
    deque(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
    }
    bool isfull(){return (size==cap);}
    bool isempty(){return (size==0);}
    void insertrear(int x)
    {
        if(isfull())return;
        arr[size]=x;
        size++;
    }
    void deleterear()
    {
        if(isempty())return;
        size--;
    }
    int getrear()
    {
        if(isempty())return -1;
        else return (size-1);
    }
    void insertfront(int x)
    {
        if(isfull()) return;
        for(int i=size-1;i>=0;i--)
            arr[i+1]=arr[i];
        arr[0]=x;
        size++;
    }
    void deletefront()
    {
        if(isempty())return;
        for(int i=0;i<size-1;i++)
            arr[i]=arr[i+1];
        size--;
    }
    int getfront()
    {
        if(isempty())return -1;
        else return 0;
    }
};
int main()
{
    deque d(5);
    d.insertfront(5);
    d.insertfront(10);
    d.insertrear(15);
    cout<<d.isfull()<<endl;
}
/*
TO MAK ITS INSERTION N REAR FOR ALL OPERATION O(1)
WE NEED TO USE CIRCULAR IMPLEMENTATION LIKE CIRCULAR QUEUE
struct deque
{
    int size,cap,front;
    int *arr;
    deque(int c)
    {
        cap=c;
        size=0;
        front=0;
        arr=new int[cap];
    }
    //functions to be adde//
}
deletefront()
    front=(front+1)%cap;
insertrear(x)
    rear=(rear+1)%cap;
insertfront(x)
    front=(front-1+cap)%cap;
deleterear()
    rear=(rear-1+cap)%cap;

// rear is always(front+size-1)%cap
*/