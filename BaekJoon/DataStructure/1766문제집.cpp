#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
vector<vector<int>> parent; //부모목록
int child[32001]; //아이수
int N,K;
priority_queue<int,vector<int>,greater<int>> que;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N>>K;
parent.resize(N+1);
for(int i=0;i<K;i++) //관계 표현
{
int a,b;
cin>>a>>b;
parent[a].push_back(b);
child[b]++;
}
for(int i=1;i<N+1;i++)
{ if(child[i]==0) que.push(i);} 
while(!que.empty())
{
    int now=que.top();
    que.pop();
    printf("%d ",now);
    for(auto i:parent[now])
    {
        child[i]--;
        if(child[i]<=0) que.push(i); 
    }
}
return 0;
}