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
class Stack
{
    private:
        Node *first;
        int size;
    public:
        Stack()
        {
            first=NULL;
            size=0;
        }
        void push(int x)
        {
            Node *temp=new Node(x);
            temp->next=first;
            first=temp;
            size++;
        }
        int pop()
        {
            if(first==NULL)
                return INT_MAX;
            int x=first->data;
            Node *temp=first;
            first=first->next;
            size--;
            delete temp;
            return x;
        }
        int peek()
        {
            if(first==NULL)
                return INT_MAX;
            return first->data;
        }
        int sz()
        {
            return size;
        }
        bool Isempty()
        {
            return size==0;
        }
};
int main()
{
    Stack s;
    s.push(5);
    s.push(10);
    cout<<s.peek()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.Isempty()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.sz()<<endl;
}