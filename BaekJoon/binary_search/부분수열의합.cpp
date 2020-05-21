#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_map<long long,long long> m1,m2;
int arr[41];
int N,K;
long long cnt=0;
void dfs(int count,int value,int start,int end)
{
    if(count>=1)
    {
        if(value==K) {cnt++;}
        if(end>N/2) m1[value]++;
        else m2[value]++;
    }
    for(int i=start;i<end;i++)
    {
        dfs(count+1,value+arr[i],i+1,end);
    }
}

int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);
cin>>N>>K;
for(int i=0;i<N;i++) cin>>arr[i];
dfs(0,0,0,N/2);
dfs(0,0,N/2,N);
for(auto i:m1)
{   long long temp=m2[K-i.first]; 
    if(temp==0) continue;
    cnt+=temp*i.second;
}
cout<<cnt;
return 0;
}