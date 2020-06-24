#include<iostream>
#include<queue>
#include<stack>
#include<functional>
#include<vector>
int **path;
using namespace std;
int Cnt=0;
struct Node{
int value; //현재값
int lower_bound;
vector<int> ordering; //순서
int visit;
};
struct compare{
    bool operator()(Node A,Node B)
    {  
        if(A.lower_bound==B.lower_bound) return A.ordering.size()<B.ordering.size();
        return A.lower_bound>B.lower_bound;
    }
};
int initial(int n,vector<int> &low)
{
Cnt=0;
path=new int*[n+1];
int lower_bound=0;
for(int i=1;i<=n;i++)
{   int minimum=2e9;
    path[i]=new int[n+1];
    for(int j=1;j<=n;j++)
    {
        cin>>path[i][j];
        if(i!=j) minimum=min(minimum,path[i][j]);
    }
    low[i]=minimum;
    lower_bound+=minimum;
}
return lower_bound;
}
void echo(Node n)
{
  /*  printf("%d 현재 탐색노드는",Cnt++);
    for(int i=0;i<n.ordering.size();i++){
        printf("%d -> ",n.ordering[i]);
    } 
    printf("\n");
    printf("lower_bound= %d, 탐색비용은 %d\n",n.lower_bound,n.value);
    */
   ;
}
void resonable_bound_function()
{  
   while(1)
   {
    int Lowest=1e9; //lower_bound;;
    int n;
    cin>>n;
    if(n==0) return;
    vector<int> low(n+1);
    vector<int> order(1,1);
    Node first={0,0,order,1}; //첫번째노드넣기
    first.lower_bound=initial(n,low);
    first.value=path[1][1];
    
    priority_queue<Node,vector<Node>,compare> que; //우선순위que
    que.push(first);
    while(!que.empty())
    {
    Node now =que.top();
    que.pop();
    echo(now);
    if(now.value>=Lowest||now.lower_bound>=Lowest) {//printf("현재 탐색경로의 lower_bound는 갱신된 값보다 크거나 같습니다\n");
     continue;}
    if(now.ordering.size()==n)
    {   now.value+=path[now.ordering.back()][1];
        now.lower_bound+=path[now.ordering.back()][1];
        now.ordering.push_back(1);
        echo(now);
        if(now.value<Lowest)
        {   
            Lowest=now.value;
      //      printf("갱신된 Lowerbound(갱신값)은 %d\n",Lowest);
        }
        else{
    //      printf("lower_bound 보다 크거나 같습니다\n");
        }
        continue;
    }
    for(int i=2;i<=n;i++)
    {   
        Node temp=now;
        if((temp.visit&1<<i)!=0) continue;
        temp.value+=path[temp.ordering.back()][i];
        temp.lower_bound+=(path[temp.ordering.back()][i]-low[temp.ordering.back()]);
        if(temp.value>=Lowest||temp.lower_bound>=Lowest) {
     //       printf("lowerbound %d 가 최대 lower_bound인  %d보다 크거나 같습니다\n",temp.lower_bound,Lowest);
            continue;
        }
        temp.visit+=1<<i; 
        temp.ordering.push_back(i);
        que.push(temp);
    }
    }
    printf("가장적은 비용은 %d\n",Lowest);
   }
}
int main()
{  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   resonable_bound_function();
   return 0;
}