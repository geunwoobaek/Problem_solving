#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define FOR(k,E,S) for(int k=S;k<=E;k++)
#define E(e) (*e)
vector<pair<int,int>> dust;//먼지담기
vector<pair<int,int>> puri; //first에는 y second에는 x
int map[51][51];
bool visit[51][51]; //먼지가있는지체크
int dx[4]={1,0,0,-1};int dy[4]={0,1,-1,0};
int R,C,T;

void diffusion() //먼지확산
{
    int map2[51][51];
    memset(map2,0,sizeof(map2));
    for(auto e: dust) //먼지들 돌림
    {
        int value=map[e.first][e.second]/5;//더해지는값
        int Sum=0; //누적횟수
        FOR(i,3,0)
        {   
            int next_y=e.first+dy[i];
            int next_x=e.second+dx[i];
            if(next_x>0&&next_y>0&&next_x<=C&&next_y<=R&&map[next_y][next_x]!=-1) //위치가 벗어나지않음
            {   
               Sum++;
               map2[next_y][next_x]+=value;
            }
        }
        map2[e.first][e.second]-=Sum*value;
    }
    FOR(i,R,1)
    {
        FOR(j,C,1)
        {   
            if(map2[i][j]!=0)
            {
            map[i][j]+=map2[i][j];
            }
        }
    }
    dust.clear();
    FOR(i,R,1)
    {
        FOR(j,C,1)
        {   
            if(map[i][j]>0) dust.push_back({i,j});
        }
    }
}
void purify() //공기청정기 이때 정렬해서 먼지를 둬야함
{    int map2[51][51];
     bool visit[51][51];
     memset(map2,0,sizeof(map2));
     memset(visit,0,sizeof(visit));
     for(vector<pair<int,int>>::iterator e=dust.begin();e!=dust.end();++e)//먼지들 실행
     {   int &next_y=(*e).first;
         int &next_x=(*e).second;
         int temp=map[next_y][next_x]; //옴기기 전값
          if(next_x==5&&next_y==1) 
           cout<<"";
         if(next_x>puri[0].second) //공기청정기보다 오른쪽에있는경우
         {  
            map2[next_y][next_x]-=temp; //먼지옴기기1
            if(next_y==1||next_y==R)next_x--; //공기청정기 가장위,아래래있을경우
            else if(next_x==C){ //벽끝에있을때 second=x first=y
            if(next_y<=puri[0].first) next_y--; //위쪽으로
            else next_y++; //밑으로
            } 
            else if((next_y==puri[0].first)||(next_y==puri[1].first))
            next_x++; //오른쪽 가는방향
           if(next_x==5&&next_y==1) 
           cout<<"";
            map2[next_y][next_x]+=temp; //위치옴기기
        } 
         else if(E(e).second==puri[0].second) //공기청정기랑 동일 colum일떄
         {  map2[next_y][next_x]-=temp;
            if(next_y>puri[0].first) next_y--;
            else next_y++;
            if(map[next_y][next_x]!=-1)
            {
                map2[next_y][next_x]+=temp;
            }
            else{  //먼지없애기 //공기청정기에 도달할때
                map2[next_y][next_x]=0;
                dust.erase(e--);
                }
         }
      }
        FOR(i,R,1)
        {
            FOR(j,C,1)
            {   
                if(map2[i][j]!=0) map[i][j]+=map2[i][j];
            }
        }
}
void Solve()
{   int total=0;
    while(T--)
    {   //sort
        diffusion();
        purify();
    }
    FOR(i,R,1)
    {
        FOR(j,C,1)
        {
            if(map[i][j]>0) total+=map[i][j];
        }
    }
    cout<<total;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>R>>C>>T;
FOR(i,R,1)
{   
    FOR(j,C,1)
    {  
        cin>>map[i][j];
        if(map[i][j]>0) dust.push_back({i,j});
        else if(map[i][j]<0) puri.push_back({i,j});
    }
}
Solve();
return 0;
}