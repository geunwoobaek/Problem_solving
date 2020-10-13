#include <iostream>
#include <vector>
 
#define endl "\n"
using namespace std;
 
int N, Block_Cnt, Score, Figure_Num = 1;
int Area[10][4][2];
vector<pair<int, pair<int, int>>> V;
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
int Min(int A, int B) { if (A < B) return A; return B; }
 
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        V.push_back(make_pair(a, make_pair(b, c)));
    }
}
 
void Setting_Block(int Shape, int x, int y)
{
    // 1 = . / 2 = ㅡ / 3 = |
    if (Shape == 1)
    {
        int B_Idx = y + 1;
        while (B_Idx < 10 && Area[B_Idx][x][0] == 0) B_Idx++;
        Area[B_Idx - 1][x][0] = Figure_Num;
        
        int G_Idx = x + 1;
        while (G_Idx < 10 && Area[G_Idx][y][1] == 0) G_Idx++;
        Area[G_Idx - 1][y][1] = Figure_Num++;
 
        Block_Cnt = Block_Cnt + 2;
    }
    else if (Shape == 2)
    {
        int B_Idx = y + 2;
        while (B_Idx < 10 && Area[B_Idx][x][0] == 0) B_Idx++;
        Area[B_Idx - 1][x][0] = Figure_Num;
        Area[B_Idx - 2][x][0] = Figure_Num;
 
        int G_Idx = x + 1;
        while (G_Idx < 10 && (Area[G_Idx][y][1] == 0 && Area[G_Idx][y + 1][1] == 0)) G_Idx++;
        Area[G_Idx - 1][y][1] = Figure_Num;
        Area[G_Idx - 1][y + 1][1] = Figure_Num++;
 
        Block_Cnt = Block_Cnt + 4;
    }
    else
    {
        int B_Idx = y + 1;
        while (B_Idx < 10 && (Area[B_Idx][x][0] == 0 && Area[B_Idx][x + 1][0] == 0)) B_Idx++;
        Area[B_Idx - 1][x][0] = Figure_Num;
        Area[B_Idx - 1][x + 1][0] = Figure_Num;
 
        int G_Idx = x + 2;
        while (G_Idx < 10 && Area[G_Idx][y][1] == 0) G_Idx++;
        Area[G_Idx - 1][y][1] = Figure_Num;
        Area[G_Idx - 2][y][1] = Figure_Num++;
 
        Block_Cnt = Block_Cnt + 4;
    }
}
 
void Remove(int Idx, int Color)
{
    for (int i = 0; i < 4; i++)
    {
        if (Area[Idx][i][Color] != 0)
        {
            Block_Cnt--;
            Area[Idx][i][Color] = 0;
        }
    }
}
 
void Move(int Idx, int Color)
{
    if (Idx == 3) return;
    
    int Move_Idx = Idx - 1;
    for (int i = 0; i < 4; i++)
    {
        if (Area[Move_Idx][i][Color] == 0) continue;
 
        int x = Move_Idx;
        int y = i;
        int Value = Area[x][y][Color];
        bool Flag = false;
 
        for (int j = 0; j < 4; j++)
        {
            int xx = Move_Idx + dy[j];
            int yy = y + dx[j];
 
            if (xx >= 4 && xx < 10 && yy >= 0 && yy < 4)
            {
                if (Area[x][y][Color] == Area[xx][yy][Color])
                {
                    Flag = true;
                    int Temp_x = x + 1;
                    int Cnt = 1;
                    while (1)
                    {
                        if (Temp_x < 10 && Area[Temp_x][y][Color] == Value)
                        {
                            Cnt = 2e9;
                            break;
                        }
                        if (Area[Temp_x][y][Color] != 0 || Temp_x >= 10) break;
                        Temp_x++;
                        Cnt++;
                    }
                    Cnt--;
 
                    int Temp_xx = xx + 1;
                    int Cnt2 = 1;
                    while (1)
                    {
                        if (Temp_xx < 10 && Area[Temp_xx][yy][Color] == Value)
                        {
                            Cnt2 = 2e9;
                            break;
                        }
                        if (Area[Temp_xx][yy][Color] != 0 || Temp_xx >= 10) break;
                        Temp_xx++;
                        Cnt2++;
                    }
                    Cnt2--;
 
                    int Move_Cnt = Min(Cnt, Cnt2);
                    Area[x + Move_Cnt][y][Color] = Area[x][y][Color];
                    Area[xx + Move_Cnt][yy][Color] = Area[xx][yy][Color];
                    if (xx + Move_Cnt == x) Area[x][y][Color] = 0;
                    else Area[x][y][Color] = Area[xx][yy][Color] = 0;
 
                    break;
                }
            }
        }
        if (Flag == false)
        {
            int Temp_x = x + 1;
            int Cnt = 1;
            while (Temp_x < 10 && Area[Temp_x][y][Color] == 0)
            {
                Temp_x++;
                Cnt++;
            }
            Cnt--;
 
            Area[x + Cnt][y][Color] = Area[x][y][Color];
            Area[x][y][Color] = 0;
        }
    }
    Move(Idx - 1, Color);
}
 
void Remove_Full_Block()
{
    bool Flag = false;
    for (int Color = 0; Color < 2; Color++)
    {
        for (int i = 6; i < 10; i++)
        {
            int Cnt = 0;
            for (int j = 0; j < 4; j++)
            {
                if(Area[i][j][Color] != 0) Cnt++;
            }
            if (Cnt == 4)
            {
                Flag = true;
                Score++;
                Remove(i, Color);
                Move(i, Color);
            }
        }
    }
    if(Flag == true) Remove_Full_Block();
}
 
void Check_Special_Point()
{
    for (int Color = 0; Color < 2; Color++)
    {
        int Cnt = 0;
        for (int SP = 4; SP < 6; SP++)
        {
            for (int i = 0; i < 4; i++)
            {
                if (Area[SP][i][Color] != 0)
                {
                    Cnt++;
                    break;
                }
            }
        }
        if (Cnt != 0)
        {
            for (int i = 0; i < Cnt; i++)
            {
                Remove(9, Color);
                Move(9, Color);
            }
        }
    }
}
 
void Solution()
{
    for (int i = 0; i < V.size(); i++)
    {
        int t = V[i].first;
        int x = V[i].second.first;
        int y = V[i].second.second;
        Setting_Block(t, x, y);
        Remove_Full_Block();
        Check_Special_Point();
    }
    cout << Score << endl << Block_Cnt << endl;
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
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

