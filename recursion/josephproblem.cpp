#include<iostream>
using namespace std;
int josh(int n,int k)
{
    if(n==1)
        return 0;
    else
        return (josh(n-1,k)+k)%n;
}