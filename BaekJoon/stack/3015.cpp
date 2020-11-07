#include <iostream>
#include <vector>
using namespace std;
#define Pair pair<int, int>
#define x first
#define y second
bool visit[4][30];
bool visit2[50];
bool isForty = false;
vector<Pair> horse(4, {0, 0});
vector<int> dice(10);
int max(int a, int b) { return a > b ? a : b; }
int map[4][30];
int _Max = 0;
void setting();
void input();
void solve();
void dfs(int res, int cur);
int main()
{
    solve();
    return 0;
}
void solve()
{
    input();
    setting();
    dfs(0, 0);
    cout << _Max;
}
void dfs(int res, int cur)
{
    _Max = max(res, _Max);
    for (int i = 0; i < horse.size() && cur < 10; i++)
    {
        Pair &one = horse[i];
        Pair copy = one;
        if (one.x == 3 && one.y == 29) continue; //마지막지점에 도달함
        if (one.x == 0&& one.y > 0&& (one.y % 5 == 0)) //Blue에 도달함!
        {
            if (one.y == 5)
                one.x = 1;
            if (one.y == 10)
                one.x = 2;
            if (one.y == 15)
                one.x = 3;
        }
        one.y += dice[cur]; //다음지점으로 이동
        //map[1][13],map[3][23],map[2][17]=끝
        if ((one.x==0&&one.y>20)||(one.x == 1 && (one.y > 12)) || (one.x == 2 && one.y > 16) || (one.x == 3 && one.y > 22))
        {
            one.x = 3;
            one.y = 29;
        }
        int cur_value = map[one.x][one.y];
        int prev_value = map[copy.x][copy.y];
        if (one.y == 29 ||(!visit[one.x][one.y] && ((!isForty) || cur_value != 40) && (one.x == 0 || !visit2[one.y])))
        {
            if (cur_value == 40) isForty = true;
            if (one.x > 0) visit2[cur_value] = true;
            if (copy.x > 0) visit2[prev_value] = false;
            visit[copy.x][copy.y] = false; //이전에방문했던거 false
            visit[one.x][one.y] = true; //현재방문한점 true
            dfs(res + cur_value, cur + 1);
            visit[one.x][one.y] = false; //현재 방문했던점 false
            visit[copy.x][copy.y] = true; //이전에 방문했던점 true
            if (cur_value == 40) //현재 value=40
                isForty = false;
           if (one.x > 0) //blueRoad로 걷고있을때
                visit2[cur_value] = false; //cur_value=false;
            if (copy.x > 0) 
                visit2[prev_value] = true;
        }
        one = copy;
    }
}
void input()
{
    for (int i = 0; i < 10; i++)
        cin >> dice[i];
}

void setting()
{
    for (int i = 1; i <= 20; i++)
        map[0][i] = 2 * i;
    map[1][6] = 13;
    map[1][7] = 16;
    map[1][8] = 19;
    map[1][9] = 25;
    map[1][10] = 30;
    map[1][11] = 35;
    map[1][12] = 40;    
    map[2][11] = 22;
    map[2][12] = 24;
    map[3][16] = 28;
    map[3][17] = 27;
    map[3][18] = 26;
    for (int i = 0; i < 4; i++)
    {
        map[2][13 + i] = map[3][19 + i] = map[1][9 + i];
    }
}