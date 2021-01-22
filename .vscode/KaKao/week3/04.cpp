#include <bits/stdc++.h>
using namespace std;
#define Vector vector<vector<int>>
#define maxNum 200001
bool Visit[maxNum] = {true};
Vector Path(maxNum);
vector<int> before(maxNum); //선결조건 ///Order[To]=From;
vector<int> after(maxNum);
queue<int, deque<int>> que;
unordered_map<int, bool> CandidateMap; //true:선결조건 충족하지 못한  next_후보군
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
    {
        if (now[1] == 0) return false;
        before[now[1]] = now[0]; //0이 해결되야 1을 할 수 있음
        after[now[0]] = now[1];
    }
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
                if (Visit[to]) //이미 방문했을시
                    continue; 
                else          //방문해야하고
                {
                    if (Visit[before[to]]) //선결조건 방문했을시
                    {
                        que.push(to);
                        Visit[to] = true;
                        if(CandidateMap[after[to]]) { //이것을 넣음으로써 선결조건 때문에 못넣은 next_후보군이라면 추가하기
                            que.push(after[to]);
                            Visit[after[to]]=true;
                            CandidateMap[after[to]]=false;
                        }
                    }
                    else  CandidateMap[to] = true; //선결집단 넣지못한 next_후보군
                }
            }
        }
    }
    if (HowManyCount == n) return true;
    else return false;
}