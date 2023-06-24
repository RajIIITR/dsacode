#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node(int d)
        {
            data=d;
            next=NULL;
        }
};
class QUEUE
{
    public:
        Node *front;
        Node *rear;
        int size;
        QUEUE()
        {
            front=NULL;
            rear=NULL;
            size=0;
        }
        void enqueue(int x)
        {
            Node *t;
            t=new Node(x);
            t->next=NULL;
            if(rear==NULL)
            {
                front=t;
                rear=t;
            }
            else
            {
                rear->next=t;
                rear=t;
            }
            size++;
        }
        int dequeue()
        {
            if(front==NULL)
                return 0;
            int x;
            x=front->data;
            front=front->next;
            size--;
            return x;
        }
        int isEmpty()
        {
            if(front==NULL && rear==NULL)
                return true;
            return false;
        }
        void display()
        {
            Node *t=front;
            while(t!=NULL)
            {
                cout<<t->data<<" ";
                t=t->next;
            }
            cout<<endl;
        }
        int getsize()
        {
            return size;
        }
};
int main()
{
    QUEUE q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    cout<<q.dequeue()<<endl;
    q.display();
    cout<<q.isEmpty()<<endl;
    cout<<q.dequeue()<<endl;
    q.display();
    cout<<q.dequeue()<<endl;
    q.display();
    cout<<q.getsize()<<endl;
}