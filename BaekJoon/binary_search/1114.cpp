#include<iostream>
#include<vector>
using namespace std;
int N,K,C;
vector<int> wood;
int LL;
void input(); void solve(); void find();
void input()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N>>K>>C; wood.resize(K+1);
for(int i=1;i<=K;i++) cin>>wood[i];
}
void lower_bound()
{
    int left=0;
    int Right=1e9;
    while(left<Right)
    {
        int mid=(left+Right)/2;
        if(findLen(mid)) Right=mid;
        else left=mid+1;
    }
    LL=left;
}
bool findLen(int mid)
{ 
    int cnt=K;
    int cur=0;
    for(int i=1;i<wood.size()&&cnt>=0;i++)
    {   
        int now=wood[i]-wood[i-1];     
        if(now>mid) return false;
        cur+=now;
        if(cur>mid) cnt--;
        cur=now;
    }
    if(cnt<0) return false;
    return true; 
}
void solve()
{
    input();
    find();
}
int main()
{
    solve();
    return 0;
}