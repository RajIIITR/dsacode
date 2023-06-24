#include<iostream>
#include<vector>
using namespace std;
class stack
{
    public:
        vector<int> v;
        void push(int x)
        {
            v.push_back(x);
        }
        int pop()
        {
            int x=v.back();
            v.pop_back();
            return x;
        }
        int size()
        {
            return v.size();
        }
        bool isEmpty()
        {
            return v.empty();
        }
        int peek()
        {
            return v.back();
        }
};