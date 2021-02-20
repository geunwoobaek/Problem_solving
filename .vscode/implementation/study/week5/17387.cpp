#include <bits/stdc++.h>
#define F(i, s, e) for (int i = s; i <= e; i++)
using namespace std;
int N, K; //체스판크기,말의갯수
/*
4 ≤ N ≤ 12
4 ≤ K ≤ 10
-> <- 위 아래
*/
int MaxCount = 0;
int turn = 0;
int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};
int Map[13][13];
int HorseMap[13][13]; //가장위에있는말
enum
{
    white,
    red,
    blue
};
//3->1->2
//2->1->3
struct Horse
{
    int num, y, x, dir, up_horse = 0, down_horse = 0;
};
vector<Horse> horses;
int getUpCount(Horse &cur)
{
    if (cur.up_horse == 0)
        return 0;
    else
        return 1 + getUpCount(horses[cur.up_horse]);
}
int getDownCount(Horse &cur)
{
    if (cur.down_horse == 0)
        return 0;
    else
        return 1 + getDownCount(horses[cur.down_horse]);
}
int getUp(Horse &cur)
{
    return cur.up_horse;
}
int getDown(Horse &cur)
{
    return cur.down_horse;
}
int getTop(Horse &cur)
{
    if (cur.up_horse == 0)
        return cur.num;
    else
        return getTop(horses[cur.up_horse]);
}
int getBottom(Horse &cur)
{

    if (cur.down_horse == 0)
        return cur.num;
    else
        return getBottom(horses[cur.down_horse]);
}
void swaping(Horse &cur)
{
    Horse *bottom = &horses[getBottom(cur)];
    Horse *top = &horses[getTop(cur)];
    Horse *before = top;
    while (bottom->num != top->num && before != bottom)
    {
        swap(bottom->num, top->num);
        before = top;
        bottom = &horses[getUp(*bottom)];
        top = &horses[getDown(*top)];
    }
}
void move(Horse &cur, int d)
{   //ffds
    int next_y = cur.y + dy[d];
    int next_x = cur.x + dx[d];
    if (Map[next_y][next_x] == blue || next_y == 0 || next_y == N || next_x == 0 || next_x == N)
    {
        if (d == 1)
            d = 2;
        else if (d == 2)
            d = 1;
        else if (d == 3)
            d = 4;
        else
            d = 3;
        next_y = cur.y + dy[d];
        next_x = cur.x + dx[d];
        if (Map[next_y][next_x] == blue || next_y == 0 || next_y == N || next_x == 0 || next_x == N)
        {
            next_y = cur.y;
            next_x = cur.x;
        }
    }
    else
    {
        if (cur.up_horse != 0) //위에말과 함께 움직이기
            move(horses[cur.up_horse], d);
        if (HorseMap[next_y][next_x] != 0) //밑에 말이 있을경우
        {
            Horse &down = horses[HorseMap[next_y][next_x]];
            down.up_horse = cur.num;
            cur.down_horse = down.num;
            MaxCount = max(MaxCount, 1 + getUpCount(cur)+getDownCount(cur));
        }
        if (Map[next_y][next_x] == red)
        {
            swaping(horses[cur.up_horse]);
            swaping(horses[cur.up_horse]);
        }
    }
    HorseMap[cur.y][cur.x] = cur.down_horse; //이동
    HorseMap[next_y][next_x] = getTop(cur);  //이동
    swap(next_y, cur.y);                     //위치이동
    swap(next_x, cur.x);                     //위치이동
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    F(i,1,N)
    {
        F(j,1,N)
        {
            cin >> Map[i][j];
        }
    }
    F(i,1,K)
    {
        Horse horse;
        horse.num = i;
        cin >> horse.y >> horse.x >> horse.dir;
        HorseMap[horse.y][horse.x] = i;
        horses.push_back(horse);
    }
    while (turn < 1000 && MaxCount < 4)
    {
        turn++;
        //  isVisit[horses] = true;
        for (Horse &cur : horses)
        {
            move(cur, cur.dir);
        }
    }
    if (MaxCount >= 4)
        cout << turn;
    else
        cout << -1;
    return 0;
}