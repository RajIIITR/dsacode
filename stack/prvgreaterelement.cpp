#include<iostream>
#include<stack>
using namespace std;
void pge(int arr[], int n)
{
    stack<int> s;
    s.push(0);
    cout<<"-1 ";
    for(int i=1;i<n;i++)
    {
        while(s.empty()==false && arr[s.top()]<=arr[i])
            s.pop();
        if(s.empty()==true)
            cout<<"-1 ";
        else
            cout<<arr[s.top()]<<" ";
        s.push(i);
    }
}
int main()
{
    int arr[7]={15, 10 , 12, 13, 11, 22, 20};
    pge(arr,7);
    return 0;
}
/*
    for nextgreaterelement Q just take 
    s.push(n-1);
    cout<<"-1 ";
    for(int i=n-2;i>=0;i--)
    {
        while(s.empty()==false && arr[s.top()]<=arr[i])
            s.pop();
        if(s.empty()==true)
            cout<<"-1 ";
        else
            cout<<arr[s.top()]<<" ";
        s.push(i);
*/