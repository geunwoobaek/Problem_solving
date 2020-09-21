#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

#define func(num) (num*num-num+2)/2
int TC;
int find(int number)
{
    int right=200;
    int left=0;
    while(left<right)
    {
        int mid=(left+right)/2;
        if(func(mid)>number)
        {
            right=mid;
        }
        else left=mid+1;
    }
    if(func(left)!=number) left--;
    return left;
}
int main()
{
cin>>TC;
int order=0;
while(++order<=TC)
{ 
    int a,b;
    cin>>a>>b;
    int a_level=find(a);
    int b_level=find(b);
    int a_pos=a-func(a_level);
    int b_pos=b-func(b_level);
    int dif_pos=a_pos-b_pos;
    if(dif_pos<0) dif_pos*=-1;
    int level_dif=a_level-b_level;
    if(level_dif<0) level_dif*=-1;
    int sum=dif_pos>=level_dif?dif_pos-level_dif:0;
    cout<<"#"<<order<<" "<<sum+level_dif<<endl;
}
return 0;
}