#include<iostream>
using namespace std;
class stack
{
    private:
        int *arr;
        int cap;
        int top;
    public:
        stack(int c)
        {
            cap=c;
            arr=new int[cap];
            top=-1;
        }
        void push(int x)
        {
            top++;
            arr[top]=x;
        }
        int pop()
        {
            int x=arr[top];
            top--;
            return x;
        }
        int peek()
        {
            int x=arr[top];
            return x;
        }
        int size()
        {
            return top+1;
        }
        bool isEmpty()
        {
            return (top==-1);
        }
};
int main()
{
    stack s(5);
    s.push(5);
    s.push(6);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
}

/*
    problem with this code :
    1)Does not handle overflow and underflow condition
    2)we need to provide the capacity as dynamic resize is not possible.we need to reuse "new" keyword to resize it!!
*/