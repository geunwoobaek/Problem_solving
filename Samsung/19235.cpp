#include <iostream>
#include <vector>
using namespace std;
//define type
#define Pair pair<int, int>
#define x second
#define y first
int bar_num = 10;
vector<vector<int>> command; //명령
int blue_board[6][4], green_board[6][4];
int N, score = 0, total = 0; //score
//함수파트
void input();
void move(vector<int>& cur);
void simulation();
void move(int pos, vector<Pair> bar, int board[][4]);
void remove(int where, Pair& RemovePoint, int board[][4]); //해당지점부터 해당지점까지 Scan해서삭제
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
            if (blue_board[i][j] != 0)
                total++;
            if (green_board[i][j] != 0)
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
void move(int pos, vector<Pair> bar, int board[][4])
{
    int how = 1; 
    if(bar.size()==2&&bar.back().second==1) 
        how = ++bar_num;
    //막대 채워넣는부분..
    bool CanGo = true;
    while (CanGo)
    {
        CanGo = bar.back().y != 6; //끝지점에 도달하는지 안하는지 체크
        //확인하는부분
        for (int i = 0; i < bar.size() && CanGo; i++)
            CanGo = board[bar[i].y][bar[i].x + pos] == 0;
        //안될경우..채워넣는 부분
        for (int i = 0; i < bar.size() && !CanGo; i++)
        {
            bar[i].y--;
            board[bar[i].y][bar[i].x + pos] = how;
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
        vector<Pair> GoDown(4);
            for (int i = 0; i < 4; i++)
        {
            for (int j = RemovePoint.y + 1; j < 6 && board[j][i] == 0; j++) //밑에부분
            {
                GoDown[i].x++; //지점부터 끝까지
            }
            int j = 0;
            for (j = RemovePoint.y; j >= 0 && board[j][i] == 0; j--) //위에부분
            {
                GoDown[i].y++; //지점부터 처음까지
            }
        }
        for (int i = 1;i <3;i++) //위치조정해주기
        {
            int now = RemovePoint.y - GoDown[i].y;
            if (board[now][i] > 10)
            {
                int next_;
                if (board[now][i] == board[now][i + 1]) next_ = i + 1;
                else if (board[now][i] == board[now][i - 1]) next_ = i - 1;
                else break;
                if (GoDown[i].y > GoDown[next_].y) GoDown[i].y = GoDown[next_].y;
                else GoDown[next_].y = GoDown[i].y;
                if (next_ > i)i++;
            }
        }
        for (int j = 0; j < 4; j++)
        {
            for (int i = RemovePoint.y - GoDown[j].y;i >= 0;i--) //지점위부터
            {
                int now = GoDown[j].y + GoDown[j].x;
                board[i + now][j] = board[i][j];
                board[i][j] = 0;
            }
        }

    }
    //밀어넣는부분
    int howManyPush = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j] != 0)
            {
                howManyPush++;
                break;
            }
    for (int i = 5; i >= 2 && howManyPush > 0; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = board[i - howManyPush][j];
            board[i - howManyPush][j] = 0;
        }
    }
}
//삭제부분
void remove(int where, Pair& RemovePoint, int board[][4])
{
    for (int i = where; i < 6; i++)
    {
        bool CanRemove = true;
        for (int j = 0; j < 4 && CanRemove; j++)
        {
            CanRemove = board[i][j] != 0;
        }
        if (CanRemove) //삭제가능할시.. 삭제
        {
            score++;
            RemovePoint.y = i;
            RemovePoint.x=1;
            for (int j = 0; j < 4; j++)
            {
                board[i][j] = 0;
            }
        }
    }
}
