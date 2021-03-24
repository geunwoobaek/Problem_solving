#include <bits/stdc++.h>
using namespace std;
#define F(i, s, e) for (int i = s; i <= e; i++)
#define Pair pair<pair<int, int>, bool>
#define y first.first
#define x first.second
#define die second
int N, M, D;
int Map[17][17];
//순열을 사용해서 모든경우를 다따져봐야함
//궁수의위치가 주어졌을때 시뮬레이션
//같은 거리 일때는 가장 왼쪽에 있는걸 죽이니깐 enmy정렬할때
//왼쪽기준으로 정렬
//(15*14*13)*3*10*15*15// 1000000
//한번에 같은놈죽일수 있으니 set자료형사용
int Max_kill = 0;
vector<Pair> Enmy;
bool kill(int acher_pos, int distance, vector<Pair> &enmy, set<int> &now_kill)
{

    F (i, 0, (int)enmy.size() - 1)
    {
        auto &cur=enmy[i];
        if (cur.die)
            continue;
        if (N + 1 - cur.y + abs(acher_pos - cur.x) == distance)
        {
            now_kill.insert(i);
            return true;
        }
    }
    return false;
}
void simulation(vector<int> &Archer, vector<Pair> enmy)
{
    int how_many_kill = 0;
    bool isOver = false;
    while (!isOver && how_many_kill != (int)enmy.size())
    {
        set<int> now_kill;
        for (auto &cur : Archer)
        {
            F(i, 1, D)
            {
                if (kill(cur, i, enmy, now_kill))
                {
                    break;
                }
            }
        }
        for (auto cur : now_kill)
        {
            enmy[cur].die = true;
            how_many_kill++;
        }
        isOver = true;
        for (auto &cur : enmy)
        {
            if (!cur.die)
            {
                cur.y += 1;
                if (cur.y == N + 1)
                    cur.die = true;
                else
                    isOver = false;
            }
        }
    }
    Max_kill = max(how_many_kill, Max_kill);
}
void Solution(int cur, vector<int> &Archer)
{
    if (Archer.size() == 3)
    {
        simulation(Archer, Enmy);
        return;
    }
    F(i, cur, M)
    {
        vector<int> next_ = Archer;
        next_.push_back(i);
        Solution(i + 1, next_);
    }
}
bool compare(Pair &a, Pair &b)
{
    return a.first.second < b.first.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> D;
    F(i, 1, N)
    F(j, 1, M)
    {
        cin >> Map[i][j];
        if (Map[i][j] == 1)
            Enmy.push_back({{i, j}, false});
    }
    sort(Enmy.begin(), Enmy.end(), compare);
    vector<int> init_Archer;
    Solution(1, init_Archer);
    cout << Max_kill;
    return 0;
}