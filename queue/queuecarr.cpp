#include<iostream>
using namespace std;
class QUEUE
{
    private:
        int size;
        int front;
        int rear;
        int *Q;
    public:
        QUEUE(int size);
        ~QUEUE();
        bool isFULL();
        bool isEMPTY();
        void enqueue(int x);
        int dequeue();
        void display();
};
QUEUE::QUEUE(int size)
{
    this->size=size;
    front=-1;
    rear=-1;
    Q=new int[size];
}
QUEUE::~QUEUE()
{
    delete []Q;
}
bool QUEUE::isEMPTY()
{
    if(front==rear)
        return true;
    return false;
}
bool QUEUE::isFULL()
{
    if(rear==size-1)
        return true;
    return false;
}
int QUEUE::dequeue()
{
    int x=-1;
    if(this->front==this->rear)
        cout<<"QUEUE IS EMPTY"<<endl;
    else
    {
        this->front=((this->front+1)%this->size);
        x=this->Q[this->front];
    }
    return x;
}
void QUEUE::enqueue(int x)
{
    if((this->rear+1)%this->size==this->front)
        cout<<"QUEUE IS FULL"<<endl;
    else
    {
        this->rear=((this->rear+1)%this->size);
        this->Q[this->rear]=x;
    }
}
void QUEUE::display()
{
    int i=this->front+1;
    do
    {
        cout<<this->Q[i]<<" ";
        i=(i+1)%this->size;
    } while (i!=((this->rear+1)%this->size));
    cout<<endl;
}
int main()
{
    QUEUE q(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(2);
    cout<<q.dequeue()<<endl;
    q.display();
}