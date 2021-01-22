#include <bits/stdc++.h>
using namespace std;
#define Vector vector<vector<int>>
#define maxNum 200001
bool Visit[maxNum] = {true};
Vector Path(maxNum);
vector<int> Order(maxNum); //선결조건 ///Order[To]=From;
queue<int> que;
vector<int> Candidate;
int HowManyCount = 0;
// BFS 탐색하다가 선결조건이 있는 노드를 만날 경우..
// (1) 선결조건 충족O-> 탐색
// (2) 선결조건 충족X  넘어가기! 후보군 리스트에 집어넣기
// (3) 후보군 리스트들에 대해서 선결조건 채워졌는지 체크하고 집어넣기.
// (4) 전부다탐색하면 탈출

bool solution(int n, Vector path, Vector order)
{
    for (auto &now : path)
    {
        Path[now[0]].push_back(now[1]);
        Path[now[1]].push_back(now[0]);
    }
    for (auto &now : order)
        Order[now[1]] = now[0]; //0이 해결되야 1을 할 수 있음
    que.push(0);
    while (!que.empty())
    {
        while (!que.empty())
        {
            int from = que.front();
          //  cout << "now = " << from << "\n";
            HowManyCount++;
            que.pop();
            for (int to : Path[from])
            {
                if (Visit[to])
                    continue; //방문했을시
                else
                {
                    if (Visit[Order[to]]) //선결조건 방문했을시
                    {
                        que.push(to);
                        Visit[to] = true;
                    }
                    else
                        Candidate.push_back(to);
                }
            }
        }

        for (vector<int>::iterator it = Candidate.begin(); it != Candidate.end();)
        {
            if (Visit[Order[*it]])
            {
                que.push(*it);
                Visit[*it] = true;
                it = Candidate.erase(it);
            }
            else
                it++;
        }
    }
    cout << HowManyCount;
    if (HowManyCount == n)
        return true;
    else
        return false;
}