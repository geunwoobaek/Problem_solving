#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tc;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cin>>tc;
while(--tc>=0)
{
int N;
cin>>N;
cout<<(N/2+N%2)<<'\n';
priority_queue<int,vector<int>,greater<>> minque; //Minqueue
priority_queue<int,vector<int>,less<>> maxque; //Maxqueue;
for(int i=1;i<=N;i++)
{
    int cur;
    cin>>cur;
    if(maxque.empty()||maxque.top()>cur) maxque.push(cur);
    else minque.push(cur);
    if(minque.size()>maxque.size()) maxque.push(minque.top()),minque.pop();
    else if(maxque.size()>minque.size()+1) minque.push(maxque.top()),maxque.pop();
    if(i%2!=0)
    cout<<maxque.top()<<" ";
}
cout<<'\n';
}

return 0;
}