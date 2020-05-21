#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
#define erase(j,i) j.erase(j.begin()+i,j.begin()+i+1)
int Map[101][101];
int R,C,N,Sum=0;
struct joss{
    int y,x,speed,d,size;
};
vector<joss> jos;
void moving(int next_y,int next_x,int k)
{  int &d=jos[k].d;
    if(next_y>R)
    {
        next_y=2*R-next_y; d=0;
        if(next_y<1) {next_y=2-next_y; d=1;}
    }
    else if(next_y<1)
    {
        next_y=2-next_y;  d=1;
        if(next_y>R) {next_y=2*R-next_y; d=0;}
    }
    else if(next_x>C)
    {
        next_x=2*C-next_x; d=3;
        if(next_x<1) {next_x=2-next_x; d=2;}
    }
    else if(next_x<1)
    {
        next_x=2-next_x; d=2;
        if(next_x>C) {next_x=2*C-next_x;d=3;}
    }
    jos[k].y=next_y;
    jos[k].x=next_x;
}
pair<int,int> D[4]={{-1,0},{1,0},{0,1},{0,-1}};
void shark_moving()
{
    int visit[101][101];
    memset(visit,-1,sizeof(visit));
    memset(Map,-1,sizeof(Map));
    for(int i=0;i<jos.size();i++)
    {   int next_y=jos[i].y+jos[i].speed*D[jos[i].d].first;
        int next_x=jos[i].x+jos[i].speed*D[jos[i].d].second;
        moving(next_y,next_x,i);
    }
    for(int i=0;i<jos.size();i++)
    {   int y=jos[i].y;
        int x=jos[i].x;
        int &V=visit[y][x];
        if(V==-1) V=i;
        else{ 
            if(jos[V].size>jos[i].size) erase(jos,i); 
            else {erase(jos,V); V=i;}       
            i--;   
        }
        Map[jos[V].y][jos[V].x]=V;
    }
}
void fishing(int k)
{
    for(int i=1;i<=R;i++)
    {   int index=Map[i][k];
        if(index!=-1) {
            Sum+=jos[index].size;
            erase(jos,index);
            break;
        }
    }
}
void solve()
{   int s=0;
    int t=C;
    while(t--)
    {
        s++;
        fishing(s);
        shark_moving();
    }
    cout<<Sum;
}
int main()
{
memset(Map,-1,sizeof(Map));
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>R>>C>>N;
jos.resize(N);
for(int i=0;i<N;i++)
{
    cin>>jos[i].y>>jos[i].x>>jos[i].speed>>jos[i].d>>jos[i].size;
    jos[i].d--;
    Map[jos[i].y][jos[i].x]=i;
    if(jos[i].d<2) jos[i].speed%=(2*R-2);
    else jos[i].speed%=(2*C-2);
}
solve();
return 0;
}