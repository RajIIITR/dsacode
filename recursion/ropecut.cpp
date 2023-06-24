#include<iostream>
#include<algorithm>
using namespace std;
int maxPieces(int n, int a, int b, int c)//time complexity:O(3^n)
{
    if(n==0) return 0;
    if(n<0) return -1;
    int res=max(maxPieces(n-a,a,b,c),max(maxPieces(n-b,a,b,c),maxPieces(n-c,a,b,c)));
    return 1+res;
}
int main()
{
    int n=23,a=12,b=9,c=11;
    cout<<maxPieces(n,a,b,c);
    return 0;
}