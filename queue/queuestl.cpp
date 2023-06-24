#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int>q;
    q.push(5);
    q.push(10);
    q.push(15);
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    cout<<q.size()<<endl;
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q.empty()<<endl;
    return 0;
}