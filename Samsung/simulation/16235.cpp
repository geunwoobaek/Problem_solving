#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<deque>
#include<algorithm>
using namespace std;
#define FOR(i,end,start) for(int i=start;i<=end;i++)
struct tree{
    int x,y,age;
};
bool compare(tree A,tree B)
{
    return A.age<B.age;
}
deque<tree> vec(0);
//vector<tree> vec(0);
vector<tree> dead(0);
int N,M,K;
int Map[101][101]; //나무의 양분담겨있음
int A[101][101]; //양분추가
int dx[8]={1,1,1,0,0,-1,-1,-1},dy[8]={0,1,-1,1,-1,0,1,-1};
//
void simulation()
{
    FOR(year,K,1)
    {
        int size=vec.size()-1>0?vec.size()-1:0;
        
        FOR(i,size,0)
        {  
            if(vec[i].age<=(year-1)*A[vec[i].y][vec[i].x]+Map[vec[i].y][vec[i].x])
            {
                Map[vec[i].y][vec[i].x]-=vec[i].age;
                vec[i].age+=1;
            }
            else
            {   // 죽음
                dead.emplace_back(vec[i]);
                vec.erase(vec.begin()+i,vec.begin()+i+1);
                i--;
                size--;
            }
        }

        size=dead.size()-1>0?dead.size()-1:0;
        FOR(i,size,0)
        {
            Map[dead[i].y][dead[i].x]+=dead[i].age/2;
        }
        dead.clear();

        size=vec.size()-1>0?vec.size()-1:0;
        FOR(i,size,0)
        {
            if(vec[i].age%5==0)
            {
                FOR(j,7,0)
                { 
                    int next_x=vec[i].x+dx[j];
                    int next_y=vec[i].y+dy[j];
                    if(next_x>0&&next_y>0&&next_x<=N&&next_y<=N)
                    {
                    // tree t={next_x,next_y,1};
                        vec.push_front(tree{next_x,next_y,1});
                        i++;
                        size++;
                    }
                }
            }
        }
    }
}
//
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cin>>N>>M>>K;
vec.resize(M);
FOR(i,N,1)
{
    FOR(j,N,1)
    {   Map[i][j]=5;
        cin>>A[i][j];
    }
}
FOR(i,M,1)
{
    cin>>vec[i-1].y>>vec[i-1].x>>vec[i-1].age;
}
sort(vec.begin(),vec.end(),compare); //나이순으로 정렬
simulation();
cout<<vec.size();
return 0;
}