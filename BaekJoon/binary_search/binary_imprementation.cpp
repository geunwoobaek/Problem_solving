#include<iostream>
#define mid (left+right)/2
using namespace std;

void binary_search(int arr[],int value)
{
int left=0;
int right=19;
while(right>=left)
{
if(arr[mid]<value) left=mid+1;
else if(arr[mid]>value) right=mid-1;
else if(arr[mid]==value) {cout<<"find"<<mid<<endl; return;}
}
cout<<"notfind"<<endl;
}
void test(int arr[])
{
for(int i=0;i<20;i++)
{
    binary_search(arr,arr[i]);
}
}

int main()
{
int arr[]={1,3,5,6,9,12,32,34,36,37,48,57,85,91,93,97,99,100,103,105};
test(arr);
return 0;
}