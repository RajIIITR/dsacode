#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//ITERATIVE WAY
void reverse(queue<int> &q)
{
    stack<int>s;
    while(q.empty()==false)
    {
        s.push(q.front());
        q.pop();
    }
    while(s.empty()==false)
    {
        q.push(s.top());
        s.pop();
    }
}
/*
RECURSIVE WAY
void reverse(queue<int> &q)
{
    if(q.empty())
        return;
    int x=q.front();
    q.pop();
    reverse(q);
    q.push(x);
}
*/