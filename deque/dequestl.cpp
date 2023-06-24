#include<iostream>
#include<deque>
using namespace std;
int main()
{
    deque<int>dq={10,20,30};
    dq.push_front(5);
    dq.push_back(50);
    for(auto x:dq)
        cout<<x<<" ";
    cout<<endl<<dq.front()<<" "<<dq.back()<<endl;
    dq.pop_front();
    dq.pop_back();
    cout<<dq.size()<<endl;
    for(auto x:dq)
        cout<<x<<" ";
    cout<<endl;
    auto it=dq.begin();
    it++;
    dq.insert(it, 25);
    for(auto x:dq)
        cout<<x<<" ";
    cout<<endl;
    return 0;
}