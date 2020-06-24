#include<iostream>
#include<queue>
#include<stack>
#include<functional>
#include<vector>
int **path;
using namespace std;

struct Node{
int value; //현재값
vector<int> ordering; //순서
int visit;
};

struct compare{
    bool operator()(Node A,Node B)
    {   if(A.value==B.value) return A.ordering.size()<B.ordering.size();
        return A.value>B.value;
    }
};
void intial(int n)
{
path=new int*[n];
for(int i=0;i<n;i++)
{   
    path[i]=new int[n];
    for(int j=0;j<n;j++)
    {
        cin>>path[i][j];
    }
}
}
void echo(Node n)
{
    cout<<"현재 탐색노드는";
    for(int i=0;i<n.ordering.size();i++){
        cout<<n.ordering[i]<<", ";
    } 
    cout<<endl;
    cout<<"총 탐색비용은 "<<n.value<<endl;
}
void resonable_bound_function()
{
   while(1)
   {
    int Lowest=1e9; //lower_bound;;
    int n;
    cin>>n;
    if(n==0) return;
    vector<int> order(1,0);
    intial(n);
    
    priority_queue<Node,vector<Node>,compare> que; //우선순위que
    Node first={path[1][1],order,1}; //첫번째노드넣기
    que.push(first);
    while(!que.empty())
    {
    Node now =que.top();
    que.pop();
    echo(now);
    if(now.value>Lowest) {cout<<"lower_bound 보다 크거나 같습니다"<<endl; continue;}
    if(now.ordering.size()==n)
    {   now.value+=path[now.ordering.back()][0];
        now.ordering.push_back(0);
        echo(now);
        if(now.value<Lowest)
        {   
            Lowest=now.value;
            cout<<"변경된 Lowerbound값은 "<<Lowest<<endl;
        }
        else{
            cout<<"lower_bound 보다 크거나 같습니다"<<endl;
        }
        continue;
    }
    for(int i=1;i<n;i++)
    {   
        Node temp=now;
        temp.value+=path[temp.ordering.back()][i];
        if((temp.visit&1<<i)!=0) continue;
        if(temp.value>Lowest) {
            cout<<temp.value<<"는 lower_bound인"<<Lowest<<"보다 큽니다"<<endl;
            continue;
        }
        temp.visit+=1<<i; 
        temp.ordering.push_back(i);
        que.push(temp);
    }
    }
    cout<<"가장적은 비용은"<<Lowest;
   }
}
int main()
{  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   resonable_bound_function();
   return 0;
}