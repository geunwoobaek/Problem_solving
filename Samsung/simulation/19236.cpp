#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> Pair;
int Maximum = 0;
#define y first 
#define x second.first
#define dir second.second 
#define size_ dir
void solve();
void input();
void simulation();
void dfs(Pair shark);
int dx[9] = { 0,0, -1, -1, -1, 0, 1, 1, 1 };
int dy[9] = { 0,-1, -1, 0, 1, 1, 1, 0, -1 };
vector<vector<int>> sea(5, vector<int>(5)); //물고기번호담겨있음
int answer = 0;
Pair Shark = { 1,{1,0} };
vector<Pair> fish(17);

int main()
{
    solve();
    return 0;
}
void solve()
{
    input();
    simulation();
    cout << Maximum;
}
void input()
{
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
        {
            int num, d;
            cin >> num >> d;
            sea[i][j] = num;
            fish[num] = { i, {j,d} };
        }
}
void simulation() {
    dfs(Shark);
}
void dfs(Pair shark)
{
    vector<Pair> fish_ = fish;
    vector<vector<int>> sea_ = sea;
    int now = sea[shark.y][shark.x];
    shark.size_ += now;
    int shark_dir = fish[now].dir;
    sea[shark.y][shark.x] = 0;
    fish[now] = { 0,{0,0} };
    Maximum = max(Maximum, shark.size_);

    //fishmove
    for (int i = 1;i < fish.size();i++) //물고기이동
    {
        if (fish[i].dir == 0) continue;
        Pair prev = fish[i]; //현재물고기위치
        for (int j = fish[i].dir;j <= 8;j++)
        {
            fish[i] = { prev.y + dy[j],{prev.x + dx[j],j} }; //위치변경
            if (fish[i].y > 0 && fish[i].x > 0 && fish[i].y <= 4 && fish[i].x <= 4 && (shark.y != fish[i].y || shark.x != fish[i].x)) break;
            j %= 8;
        }
        int changed_fish_num = sea[fish[i].y][fish[i].x]; //변경될위치에갈 물고기번호
        //map변경
        sea[fish[i].y][fish[i].x] = i;
        sea[prev.y][prev.x] = changed_fish_num;
        if (changed_fish_num == 0) continue; //물고기가업을떄
        prev.dir = fish[changed_fish_num].dir;
        fish[changed_fish_num] = prev; //물고기위치변경완료
    }
    for (int i = 1;i < 4;i++)
    {
        Pair next = { shark.y + i*dy[shark_dir],{shark.x + i*dx[shark_dir],shark.size_} };
        if (next.y > 0 && next.x > 0 && next.y <= 4 && next.x <= 4 && sea[next.y][next.x] != 0)
            dfs(next);
    }
    fish = fish_;
    sea = sea_;
}
