#include<iostream>
using namespace std;
int lower_bound(int size,int arr[],int value)
{ 
    int left=0;
    int right=size-1;
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]<value)
        {
            right=mid;
        }   
        else{
            left=mid+1;
        }
    }
    return arr[left];
}
void printarr(int arr[])
{
for(int i=0;i<10;i++) cout<<arr[i];
}
int main()
{
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int arr2[9]={1,2,3,4,5,6,7,8,9};

    for(int i=0;i<10;i++)
    {
        cout<<lower_bound(10,arr,i);
    }
    cout<<endl;
     for(int i=0;i<9;i++)
    {
        cout<<lower_bound(9,arr2,i);
    }
    return 0;
}