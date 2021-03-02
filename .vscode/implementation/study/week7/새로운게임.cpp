#include<bits/stdc++.h>
 
#define endl "\n"
#define MAX 12
#define CHESS_MAX 10
using namespace std;
 
struct CHESS        // 말을 관리하는 구조체
{
    int x;
    int y;
    int dir;
    bool Under;
};
 
int N, K;
int MAP[MAX][MAX];
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };
CHESS Chess[CHESS_MAX];
vector<int> MAP_State[MAX][MAX];    // 맵의 상태를 나타내는 벡터 2차원 배열.
 
void Input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int x, y, d; cin >> x >> y >> d;
        x--; y--;
        Chess[i] = { x, y, d, true };
        MAP_State[x][y].push_back(i);
    }
}
 
void Reverse_Chess(int x, int y)
{
    /* 
    (x , y)에 존재하는 말의 순서를 뒤집는 함수 
    - 'Temp' 라는 임시 벡터에 (x, y)에 있는 모든 말들을 옮겨주고 
      거꾸로 (x, y)에 넣어주었다.
    - 가장 아래에 위치한 말이 달라지니 Check.
    */
    vector<int> Temp;
    for (int i = 0; i < MAP_State[x][y].size(); i++) Temp.push_back(MAP_State[x][y][i]);
    MAP_State[x][y].clear();
    for (int i = Temp.size() - 1; i >= 0; i--)
    {
        MAP_State[x][y].push_back(Temp[i]);
        Chess[Temp[i]].Under = false;
    }
    Chess[MAP_State[x][y][0]].Under = true;
}
 
int Reverse_Dir(int d)
{
    /* 방향 전환 함수 */
    if (d == 1) return 2;
    else if (d == 2) return 1;
    else if (d == 3) return 4;
    else if (d == 4) return 3;
}
 
void Change_State(int x, int y, int nx, int ny, int Ms)
{
    /* 실제로 말을 움직이는 함수 */
    if (Ms == 0)    // 1번 Case. (nx, ny) = 0
    {
        if (MAP_State[nx][ny].size() != 0) Chess[MAP_State[x][y][0]].Under = false;    
        for (int j = 0; j < MAP_State[x][y].size(); j++)
        {
            MAP_State[nx][ny].push_back(MAP_State[x][y][j]);
            int Idx = MAP_State[x][y][j];
            Chess[Idx].x = nx;
            Chess[Idx].y = ny;
        }
        MAP_State[x][y].clear();
    }
    else if (Ms == 1)    // 2번 Case. (nx, ny) = 1
    {
        Reverse_Chess(x, y);
        for (int i = 0; i < MAP_State[x][y].size(); i++)
        {
            MAP_State[nx][ny].push_back(MAP_State[x][y][i]);
            int Idx = MAP_State[x][y][i];
            Chess[Idx].x = nx;
            Chess[Idx].y = ny;
        }
        MAP_State[x][y].clear();
        for (int i = 1; i < MAP_State[nx][ny].size(); i++)
        {
            Chess[MAP_State[nx][ny][i]].Under = false;
        }
    }
    else if (Ms == 2)    // 3번 Case. (nx, ny) = 2
    {
        int Dir = Reverse_Dir(Chess[MAP_State[x][y][0]].dir);
        Chess[MAP_State[x][y][0]].dir = Dir;
        int nnx = Chess[MAP_State[x][y][0]].x + dx[Dir];
        int nny = Chess[MAP_State[x][y][0]].y + dy[Dir];
 
        if (nnx >= 0 && nny >= 0 && nnx < N && nny < N)
        {
            if (MAP[nnx][nny] != 2) Change_State(x, y, nnx, nny, MAP[nnx][nny]);
        }
    }
}
 
bool Check_State()
{
    for(int i = 0 ; i < K; i++)
    { 
        int x = Chess[i].x;
        int y = Chess[i].y;
        
        if (MAP_State[x][y].size() >= 4) return true;
    }
    return false;
}
 
void Solution()
{
    bool Flag = false;
    int Cnt = 0;
    while (1)
    {
        if (Check_State() == true)
        {
            Flag = true;
            break;
        }
        if (Cnt > 1000) break;
 
        for (int i = 0; i < K; i++)
        {
            if (Chess[i].Under == false) continue;
            int x = Chess[i].x;
            int y = Chess[i].y;
            int Dir = Chess[i].dir;
 
            int nx = x + dx[Dir];
            int ny = y + dy[Dir];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N) Change_State(x, y, nx, ny, MAP[nx][ny]);
            else Change_State(x, y, nx, ny, 2);
        }
        Cnt++;
    }
 
    if (Flag == true) cout << Cnt << endl;
    else cout << -1 << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();

    return 0;
}