/*
1) Initialize Maximal Matching M as empty.
2) While there exists an Augmenting Path p
     Remove matching edges of p from M and add not-matching edges of p to M
     (This increases size of M by 1 as p starts and ends with a free vertex)
3) Return M. 
*/
#include <bits/stdc++.h>

using namespace std;
//① 교차 경로(alternating path)
//② 증가 경로(augmenting path)
vector<vector<int>> u(5, vector<int>()); //u와 이어진 노드들 교차경로+증가경로
vector<vector<int>> v(5, vector<int>()); //to로 향하는 경로  교차경로+증가경로
vector<int> alternatingPathFrom(5);
vector<int> alternatingPathTo(5);
void addEdge(int from, int to)
{
    u[from].push_back({to});
    v[to].push_back({from});
}
void matching()
{

    for (int i = 1; i <= 5; i++)
    {
        for (auto &cur : u[i])
        {
            if (alternatingPathTo[cur] == 0) //연결 안됐을시
            {
                alternatingPathTo[cur] = i;
                alternatingPathFrom[i] = cur;
                break;
            }
        }
    }
}
void search(int )
void hopcroft_karp(){
    for(int i:alternatingPathFrom){
        if(alternatingPathFrom[i]==0){ //만약 매칭된게 없을시
        dfs(i,true)

        }
    }
}
int main()
{
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(2, 1);
    addEdge(3, 2);
    addEdge(4, 2);
    addEdge(4, 4);
    matching(); //matching
    return 0;
}