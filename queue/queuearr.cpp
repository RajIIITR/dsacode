#include<iostream>
using namespace std;
class QUEUE
{
    public:
        int size,cap;
        int *arr;
        QUEUE(int c)
        {
            cap=c;
            size=0;
            arr=new int;
        }
        void enque(int x);
        int deque();
        bool Isempty();
        int getfront();
        int getrear();
        int display();
        bool Isfull();
};
bool QUEUE::Isempty()
{
    return(size==0);
}
bool QUEUE::Isfull()
{
    return(size==cap);
}
void QUEUE::enque(int x)
{
    if(Isfull())
    {return ;}
    arr[size]=x;
    size++;
}
int QUEUE::deque()
{
    if(Isempty())
    {return 1;}
    int x=arr[0];
    for(int i=0;i<size-1;i++)
        arr[i]=arr[i+1];
    size--;
    return x;
}
int QUEUE::getfront()
{
    if(Isempty())
        return -1;
    else 
        return 0;
}
int QUEUE::getrear()
{
    if(Isempty())
        return -1;
    else    
        return size-1;
}
int QUEUE::display()
{
    cout<<endl;
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    QUEUE q(5);
    q.enque(1);
    q.enque(2);
    q.display();
    cout<<q.deque();
    return 0;
}