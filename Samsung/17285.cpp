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
        if (one.first == 3 && one.second == 29)
            continue; //마지막지점에 도달함
        if (one.first == 0&& one.second > 0&& (one.second % 5 == 0))
        {
            if (one.second == 5)
                one.first = 1;
            if (one.second == 10)
                one.first = 2;
            if (one.second == 15)
                one.first = 3;
        }
        one.second += dice[cur];
        //map[1][13],map[3][23],map[2][17]=끝
        if ((one.first==0&&one.second>20)||(one.first == 1 && (one.second > 12)) || (one.first == 2 && one.second > 16) || (one.first == 3 && one.second > 22))
        {
            one.first = 3;
            one.second = 29;
        }
        int cur_value = map[one.first][one.second];
        int prev_value = map[copy.first][copy.second];
        if (one.second == 29 ||(!visit[one.first][one.second] && ((!isForty) || cur_value != 40) && (one.first == 0 || !visit2[one.second])))
        {
            if (cur_value == 40)
                isForty = true;
            if (one.first > 0)
                visit2[cur_value] = true;
            if (copy.first > 0)
                visit2[prev_value] = false;
            visit[copy.first][copy.second] = false;
            visit[one.first][one.second] = true;
            dfs(res + cur_value, cur + 1);
            visit[one.first][one.second] = false;
            visit[copy.first][copy.second] = true;
            if (cur_value == 40)
                isForty = false;
           if (one.first > 0)
                visit2[cur_value] = false;
            if (copy.first > 0)
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