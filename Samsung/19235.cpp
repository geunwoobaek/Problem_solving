#include <iostream>
#include <vector>
using namespace std;
//define type
#define Pair pair<int, int>
#define y first
#define x second
vector<vector<int>> command; //명령
bool blue_board[6][4], green_board[6][4];
int N, score = 0, total = 0; //score
//함수파트
Pair next_[2] = { {1, 0}, {0, 1} };
void input();
void move(vector<int>& cur);
void simulation();
void move(int pos, vector<Pair> bar, bool board[][4]);
void remove(int where, Pair& RemovePoint, bool board[][4]); //해당지점부터 해당지점까지 Scan해서삭제
void solve();

int main()
{
    solve();
}
void solve()
{
    input();
    simulation();
    cout << score << "\n" << total;
}
void simulation()
{
    for (auto now : command)
    {
        move(now);
    }
    for (int i = 2; i < 6; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (blue_board[i][j])
                total++;
            if (green_board[i][j])
                total++;
        }
    }
}
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    command.resize(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> command[i][j];
    }
}
void move(vector<int>& cur) //모드,행,열
{
    vector<Pair> bar;
    //bar결정
    bar.push_back({ 0, 0 });
    if (cur[0] == 2)
        bar.push_back({ 0, 1 });
    else if (cur[0] == 3)
        bar.push_back({ 1, 0 });
    //green에 넣을거
    move(cur[2], bar, green_board); //열정보만 넣음
    //blue에 넣을거
    for (int i = 0; i < bar.size(); i++)
    {
        int temp = bar[i].x;
        bar[i].x = bar[i].y;
        bar[i].y = temp;
    }
    move(cur[1], bar, blue_board); //열정보만 넣음
}
void move(int pos, vector<Pair> bar, bool board[][4])
{
    //막대 채워넣는부분..
    bool CanGo = true;
    while (CanGo)
    {
        CanGo = bar.back().y != 6; //끝지점에 도달하는지 안하는지 체크
        //확인하는부분
        for (int i = 0; i < bar.size() && CanGo; i++)
            CanGo = !board[bar[i].y][bar[i].x + pos];
        //안될경우..채워넣는 부분
        for (int i = 0; i < bar.size() && !CanGo; i++)
        {
            bar[i].y--;
            board[bar[i].y][bar[i].x + pos] = true;
        }
        //증가부분
        for (int i = 0; i < bar.size() && CanGo; i++)
            bar[i].y++;
    }

    Pair RemovePoint = { 0, 0 }; //삭제지점:Clear되는시점
    //삭제부분
    while (true)
    {   
        remove(RemovePoint.y, RemovePoint, board);
        if (--RemovePoint.x < 0)
            break;
        vector<int> goBlock(4, 1 + RemovePoint.x);
        for (int i = 0; i < 4 && RemovePoint.y < 5; i++)
        {
            bool up = board[RemovePoint.y - 1 - RemovePoint.x][i];
            bool down = board[RemovePoint.y + 1][i];
            if (!down)
                goBlock[i]++;
        }
        for (int i = RemovePoint.y - 1-RemovePoint.x; i >= 0; i--) //삭제한부분부터 그윗부분들 밑으로 내리기..
        {
            for (int j = 0; j < 4; j++)
            {
                board[i + goBlock[j]][j] = board[i][j];
            }
        }
    }
    //밀어넣는부분
    int howManyPush = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j])
            {
                howManyPush++;
                break;
            }
    for (int i = 5; i >= 2 && howManyPush > 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = board[i - howManyPush][j];
            board[i - howManyPush][j] = false;
        }
    }
}
//삭제부분
void remove(int where, Pair& RemovePoint, bool board[][4])
{
    for (int i = where; i < 6; i++)
    {
        bool CanRemove = true;
        for (int j = 0; j < 4 && CanRemove; j++)
        {
            CanRemove = board[i][j];
        }
        if (CanRemove) //삭제가능할시.. 삭제
        {
            score++;
            RemovePoint.y = i;
            RemovePoint.x++;
            for (int j = 0; j < 4; j++)
            {
                board[i][j] = false;
            }
        }
    }
}
