#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
struct command{
    int num,d,cnt;
};
int N,M,T;
int total=0;
vector<command> cmd;
vector<vector<int>> circle;
void rotate(command C)
{   C.cnt%=M;
    while(C.cnt--)
    {
        if(C.d==0) //시계방향으로
        {   int front=circle[C.num].back();
            circle[C.num].erase(circle[C.num].end()-1,circle[C.num].end());
            circle[C.num].insert(circle[C.num].begin()+1,front);
        }
        else{ //반시계방향
            circle[C.num].push_back(circle[C.num][1]);
            circle[C.num].erase(circle[C.num].begin()+1,circle[C.num].begin()+2);
        }
    }
}
void Check()
{
 //배열에서 arr[2][1] [3][1] [1][1] [2][2]
 bool check[51][51];
 double averagesum=0;
 bool on=false;
 memset(check,false,sizeof(check));
 int cnt=0;
 for(int i=1;i<=N;i++) //인접한부분 체크
 {  
     for(int j=1;j<=M;j++)
     {   if(circle[i][j]==0) {cnt++;continue;}
         else averagesum+=circle[i][j];

         if(j!=M&&(circle[i][j]==circle[i][j+1]))
         {   on=true;
             check[i][j]=true;
             check[i][j+1]=true;
         }
         else if(j==M&&(circle[i][j]==circle[i][1])) 
         {   on=true;
             check[i][j]=true;
             check[i][1]=true;
         }
         
         if(i!=N&&(circle[i][j]==circle[i+1][j]))
         {   on=true;
             check[i][j]=true;
             check[i+1][j]=true;
         }
     }
 }
 if(cnt!=N*M)
 averagesum/=(N*M-cnt); //원판에대한 평균값
 if(on) //인접부분존재할경우
 {
     for(int i=1;i<=N;i++) //인접한부분 체크
     {
     for(int j=1;j<=M;j++)
     {
         if(check[i][j]) 
         {
         total-=circle[i][j];
         circle[i][j]=0;
         }
     }
     }
 }
 else
 {
     for(int i=1;i<=N;i++) //인접한부분 체크
     {
     for(int j=1;j<=M;j++)
     {   if(circle[i][j]==0) continue;
         if(circle[i][j]>averagesum) {total--;circle[i][j]--;}
         else if(circle[i][j]<averagesum) {total++;circle[i][j]++;}
     }
     }
 }
}
void simulation()
{
    for(auto c:cmd)
    {   int k=c.num;
        for(int i=1;i*k<=N;i++)
        {
        c.num=k*i; 
        rotate(c);
        }
        Check();
    }
    cout<<total;
}
int main()
{ 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N>>M>>T;
circle.resize(N+1,vector<int>(M+1,0));
cmd.resize(T);
for(int i=1;i<=N;i++)
{
    for(int j=1;j<=M;j++)
    {
        cin>>circle[i][j];
        total+=circle[i][j];
    }
}
for(int i=0;i<T;i++)
{
    cin>>cmd[i].num>>cmd[i].d>>cmd[i].cnt;
}
simulation();
return 0;
}