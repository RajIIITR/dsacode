#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(50);
    s.push(40);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}