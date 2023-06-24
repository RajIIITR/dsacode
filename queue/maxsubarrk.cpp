#include<iostream>
#include<deque>
using namespace std;
void Printmax(int arr[], int n, int k)
{
    deque<int>dq;
    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i=k;i<n;i++)
    {
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
        while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
        dq.pop_back();
    }
    cout<<arr[dq.front()]<<" ";
}