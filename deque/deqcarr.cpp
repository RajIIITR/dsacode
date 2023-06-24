#include<iostream>
using namespace std;
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
    bool isfull(){return (size==cap);}
    bool isempty(){return (size==0);}
    void deletefront()
    {
        if(isempty())return;
        front=(front+1)%cap;
        size--;
    }
    void insertrear(int x)
    {
        if(isfull())return;
        int new_rear=(front+size)%cap;
        arr[new_rear]=x;
        size++;
    }
    int getfront()
    {
        if(isempty())return -1;
        else return front;
    }
    void insertfront(int x)
    {
        if(isfull())return;
        front=(front+cap-1)%cap;
        arr[front]=x;
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
        else return (front+size-1)%cap;
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