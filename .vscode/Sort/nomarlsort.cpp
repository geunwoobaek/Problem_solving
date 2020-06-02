#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[20]={12,32,14,43,55,21,11,31,5,17,9,4,2,100,49,321,134,27,33,19};
    int goal[20];
    for(int i=0;i<20;i++)
    {   int target=i;
        for(int j=0;j<20;j++)
        {
            if(arr[target]<arr[j])
            target=j;
        }
        goal[i]=arr[target];
        arr[target]=0;
    }
    for(int i=0;i<20;i++) cout<<goal[i]<<endl;
}