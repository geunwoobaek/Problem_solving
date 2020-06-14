#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,W;
int visit[100][100001];
int Maximum=0;
struct order{
    int weight,value,number;
};
queue<order> que;
vector<order> vec;
int main()
{
 ios_base::sync_with_stdio(false);cin.tie(NULL);
cin>>N>>W;
for(int i=0;i<N;i++)
{   order temp;
    temp.number=i+1;
    cin>>temp.weight>>temp.value;
    visit[i][temp.weight]=temp.value;
    vec.push_back(temp);
    que.push(temp);
}
while(!que.empty())
{
    order now=que.front();
    que.pop();
    if(Maximum<now.value) Maximum=now.value;
    for(int i=now.number;i<N;i++)
    {   order temp=now;
        temp.weight+=vec[i].weight;
        temp.value+=vec[i].value;
        temp.number=i+1;
        if(temp.weight<=W&&visit[i][temp.weight]<temp.value)
        {   
            visit[i][temp.weight]=temp.value;
            que.push(temp);
        }
    }
}
cout<<Maximum;
return 0;
}