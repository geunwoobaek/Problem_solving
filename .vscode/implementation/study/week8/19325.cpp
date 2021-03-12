#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int, int>
#define Block vector<Pair>
#define y first
#define x second
#define fill true
#define empty false
int N; //N(1 ≤ N ≤ 10,000)
bool Map[11][11];
int dy[2] = {0, 1}, dx[2] = {1, 0};
int score = 0;
vector<Block> blokcs = {{{0, 0}}, {{0, 0}, {0, 1}}, {{0, 0}, {1, 0}}};
bool isRange(Block &next)
{
    for (auto &cur : next)
    {
        if (cur.y > 10 || cur.x > 10 || Map[cur.y][cur.x] == fill)
            return false;
    }
    return true;
}
void goDown(int Y, int X, int mode) //밑으로 밀어넣기
{
    if (mode == 0)
        Map[Y][X] = Map[Y - dy[mode]][X - dx[mode]];
    else
        Map[X][Y] = Map[X - dy[mode]][Y - dx[mode]];
}
void simulation(int y, int x, Block init_block)
{
    //1. 블록 이동
    for (int mode = 0; mode < 2; mode++)
    {
        Block block = init_block;
        while (1) //go
        {
            Block next = block;
            for (auto &one : next)
            {
                one.y += dy[mode];
                one.x += dx[mode];
            }
            if (isRange(next))
                swap(block, next);
            else
                break;
        }
        //2. 옅은줄에 걸쳤는지 확인
        int go = 0;
        for (auto &one : block)
        {
            if (one.y == 5 || one.x == 5 || one.y == 6 || one.x == 6)
                go++;
        }
        while (go-- > 0)
        {
            int Y, X;
            for (Y = 10; Y >= 5; Y--)
                for (X = 1; X <= 4; X++)
                    goDown(Y,X,mode);
        }
        //3. 라인이 완성됐는지 보기
        //밑에서부터 확인후 제거 되면 제거 된 윗지점부터 밑으로 내려오게 하기

         for (int Y = 10; Y >= 5; Y--)
                if(check(Y,mode)==fill){
                    remove(Y,mode);
                }

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    while (N--)
    {
        int y, x, what;
        simulation(y, x, blokcs[what]);
    }
}
