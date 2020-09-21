#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;
static int Start = 'a';
int FULL = (1 << 26) - 1;
int MaxCount = 0;
vector<int> arr;
int find(int number)
{
    int right=10;
    int left=0;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(arr[mid]>number)
        {
            right=mid;
        }
        else left=mid+1;
    }
    return left;
}
int main()
{
   arr.resize(10);
   for(int i=0;i<10;i++) arr[i]=i;
   for(int i=0;i<10;i++) cout<<find(i)<<endl;
   return 0;
}