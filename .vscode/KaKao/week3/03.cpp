#include <bits/stdc++.h>
using namespace std;
#define Vector vector<vector<int>>
bool Visit[200000] = {
    true,
};
Vector OrderToFromMap(200000); //key=방문하고 싶은 방 value=이전에 방문해야할방
Vector OrderFromToMap(200000); //key=이전에 방문해야 할방 value=방문하고 싶은 방
Vector Route(200000);
queue<int> que;
bool CanGo(int to) {
    for (auto& from : OrderToFromMap[to]) {
        if (!Visit[from]) return false;
    }
    return true;
}
bool solution(int n, Vector path, Vector order)
{
    for (auto& now : order)
    {
            OrderToFromMap[now[1]].push_back(now[0]);
        OrderFromToMap[now[0]].push_back(now[1]);
    }
    for (auto& cur : path)
    {
           Route[cur[0]].push_back(cur[1]);
        Route[cur[1]].push_back(cur[0]);
    }
    que.push(0);
    while (!que.empty())
    {
        int from = que.front();
        que.pop();
        for (auto& to : Route[from])
        {
            if (!Visit[to] && CanGo(to)) //push할조건
            {
                Visit[to] = true;
                que.push(to);
                DfsVisit(to);
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (!Visit[i])
            return false;
    return true;
}
int main()
{
    solution(9,
        { {0, 1},
         {0, 3},
         {0, 7},
         {8, 1},
         {3, 6},
         {1, 2},
         {4, 7},
         {7, 5} },
        { {8, 5},
         {6, 7},
         {4, 1} });
}