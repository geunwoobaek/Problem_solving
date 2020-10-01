#include<iostream>
using namespace std;

int *arr=new int[100];
int lowerbound(int v)
{
    int left=0;
    int right=9;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(arr[mid]>v) right=mid-1;
        else left=mid+1;
    }
    return arr[right];
}
int main()
{
for(int i=0;i<100;i++) arr[i]=i+1;  
for(int i=1;i<=100;i++) 
{  
    cout<<lowerbound(i)<<endl;
}

return 0;
}