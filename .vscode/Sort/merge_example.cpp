#include<iostream>
#include<vector>
using namespace std;
#define total 20
int arr[]={12,32,14,43,55,21,11,31,5,17,9,4,2,100,49,321,134,27,33,19};
void merge(int left,int right)
{
    int mid=(left+right)/2; //
    int point1=left,point2=mid+1; 
    int arr2[total]; //2차배열크기
    int index=left;
    while(point1<=mid&&point2<=right)
    {
        if(arr[point1]>arr[point2]) arr2[index++]=arr[point2++];
        else arr2[index++]=arr[point1++];
    }
    while(point1<=mid) arr2[index++] = arr[point1++];
    while(point2<=right) arr2[index++] = arr[point2++];
    copy(arr2+left,arr2+right+1,arr+left);
    cout<<"";
}
//끝까지 분할한다음에 2개가 나오면 그때합침
void devide(int left,int right)
{
int mid=0;
 if(right>left)
 {   
     mid=(int)((right+left)/2);
     devide(left,mid);
     devide(mid+1,right);
     merge(left,right);
 }
}
int main()
{
devide(0,19);
for(int i=0;i<20;i++) cout<<arr[i]<<endl;
}