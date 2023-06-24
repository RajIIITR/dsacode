#include<iostream>
using namespace std;
int countsubset(int arr[],int n,int sum)
{
    if(n==0)
        return (sum==0)?1:0;
    return countsubset(arr,n-1,sum)+ countsubset(arr,n-1,sum-arr[n-1]);
}