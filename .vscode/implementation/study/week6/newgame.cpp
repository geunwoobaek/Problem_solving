#include <bits/stdc++.h>
using namespace std;
#define F(i, s, e) for (int i = s; i <= e; i++)
int N, K;
int Map[13][13];
int Horse_Map[13][13];
int dy[5] = {0, 0, 0, -1, 1}; //0 -> <- ^ v
int dx[5] = {0, 1, -1, 0, 0};
struct Horse
{
    int num, y, x, dir;
    int up_horse = 0;
    int down_horse = 0;
};
enum
{
    WHITE,
    RED,
    BLUE
};
vector<Horse> horses;
bool IsRange(Horse &horse)
{
    return horse.y > 0 && horse.x > 0 && horse.y <= N && horse.x <= N;
}
void SwapDir(Horse &horse)
{
    if (horse.dir == 1)
        horse.dir = 2;
    else if (horse.dir == 2)
        horse.dir = 1;
    else if (horse.dir == 3)
        horse.dir = 4;
    else if (horse.dir == 4)
        horse.dir = 3;
}
int UP(int cur)
{
    Horse &horse = horses[cur];
    if (horse.up_horse == 0)
        return horse.num;
    else
        return UP(horse.up_horse);
}
int BOTTOM(int cur)
{
    Horse &horse = horses[cur];
    if (horse.down_horse == 0)
        return horse.num;
    else
        return BOTTOM(horse.down_horse);
}
void move_horse(Horse *horse, int dir)
{
    Horse next = *horse;
    next.y += dy[dir];
    next.x += dx[dir];
    if (IsRange(next) && Map[next.y][next.x] != BLUE) //다음지점 갈 수 있을경우는
    {
        //1.이동할때 발밑의 말 위를 비워주기
        Horse &down = horses[horse->down_horse];
        down.up_horse = 0;
        //1.1 HorseMap변경
        Horse_Map[horse->y][horse->x] = down.num;
        //2.다음지점으로 이동
        swap(*horse, next);
        //3.이동하는 말의 밑 변경및 위 변경
        horse->down_horse = Horse_Map[horse->y][horse->x];
        if (Horse_Map[horse->y][horse->x] != 0)
        {
            horses[horse->down_horse].up_horse = horse->num;
        }
        //4. Horse_Map변경
        Horse_Map[horse->y][horse->x] = horse->num;
        //5. 이동한지점 위의 말변경및 horseMap변경
        int up_horse = horse->up_horse;
        while (up_horse != 0)
        {
            horses[up_horse].y = horse->y;
            horses[up_horse].x = horse->x;
            Horse_Map[horse->y][horse->x] = up_horse;
            up_horse = horses[up_horse].up_horse;
        }
    }
}
int TotalStack(int now)
{
    if (horses[now].down_horse != 0)
        return 1 + TotalStack(horses[horses[now].down_horse].num);
    else
        return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    horses.resize(K + 1);
    F(i, 1, N)
    F(j, 1, N)
    cin >> Map[i][j];
    F(i, 1, K)
    {
        cin >> horses[i].y >> horses[i].x >> horses[i].dir;
        Horse_Map[horses[i].y][horses[i].x] = horses[i].num = i;
    }
    F(turn, 1, 1000)
    {
        for (auto &next : horses)
        {
            Horse temp = next;
            temp.y += dy[temp.dir];
            temp.x += dx[temp.dir];
            if (!IsRange(temp) || (Map[temp.y][temp.x] == BLUE)) //Blue일경우
                SwapDir(next);                                   //방향변경
            move_horse(&next, next.dir);      //말이동
            if (Map[next.y][next.x] == RED) //red일경우
            {
                int up = Horse_Map[next.y][next.x];
                int bottom=temp.down_horse;
                while (up != bottom)
                {
                    swap(horses[up].up_horse, horses[up].down_horse);
                    up = horses[up].up_horse;
                }
                horses[Horse_Map[next.y][next.x]].down_horse=bottom; //
                horses[up].up_horse=0;
                Horse_Map[next.y][next.x] = temp.num;
            }
            if (TotalStack(Horse_Map[next.y][next.x]) >= 4) //갯수세기
            {
                // cout << "turn" << turn << ":\n";
                // F(i, 1, N)
                // {
                //     F(j, 1, N)
                //     cout << Horse_Map[i][j] << " ";
                //     cout << "\n";
                // }
                std::cout << turn;
                exit(0);
            }
        }
    }
    cout << -1;
    return 0;
}
