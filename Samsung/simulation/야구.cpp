#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#define FOR(i,end,start) for(int i=start;i<=end;i++)
using namespace std;
int N;
vector<vector<int>> base;
bool visit[10];
int Max;
void simul(vector<int> order)
{  int score=0;
   vector<vector<int>> all(N+1);
   int arr[4]={100000,0,0,0};
    FOR(i,N,1)
    {   all[i].resize(10);
        FOR(j,9,1)
        {
            all[i][j]=base[i][order[j]];
        }
    }
    FOR(i,N,1)
    {   int out=0;
        int arr[4]={1000,0,0,0};
        FOR(j,9,1)
        {
           if(all[i][j]!=0)
           {
            for(int k=3;k>=0;k--)
           {
               if(arr[k]!=0)
               {
                arr[k]--;
               if(k+all[i][j]>3)
                score++;
               else arr[k+all[i][j]]++;
               }
           }
           }
           else 
           { 
            out++; 
            if(out==3)
            {
                i++; out=0;
                arr[0]=1000;arr[1]=0;arr[2]=0;arr[3]=0;
                if(i>N) break;
            } 
           }
           if(j==9) j=0;
        }
    }
   Max=Max>score?Max:score;
}
void dfs(int depth,vector<int> order) //order도 1부터
{
    if(depth==9)
    {   
        simul(order);
        return;
    }
    else if(depth==3)
    {
        depth+=1;
    }
   FOR(i,9,1)
   {
       if(!visit[i])
       {
           visit[i]=true;
           order[depth+1]=i;
           dfs(depth+1,order);
           visit[i]=false;
       }
   }
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N;
base.resize(N+1);
FOR(i,N,1)
{
base[i].resize(10);
FOR(j,9,1)
{   
cin>>base[i][j];
}
}
vector<int> order(10);
order[4]=1;
visit[1]=true;
dfs(0,order);
cout<<Max;
return 0;
}