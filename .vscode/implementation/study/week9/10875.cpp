#include <bits/stdc++.h>
using namespace std;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0}; //동 남 서 북
int now_dir = 0, N, M;
int result = 0;
void rotate(char dir)
{
    if (dir == 'R')
        now_dir = now_dir != 3 ? now_dir + 1 : 0;
    else if (dir == 'L')
        now_dir = now_dir != 0 ? now_dir - 1 : 3;
}
struct Info
{
    int start_x, start_y, end_x, end_y;
    bool isColum;
};
struct Position
{
    int x, y;
};
bool canGo(Info A, Info B)
{   
    if(A.isColum==B.isColum){
        if(A.isColum){
            
        }
        else{

        }
    }
    if (A.start_x == A.end_x)  swap(A, B); //A는 start_y, end_y는 똑같다.
    return A.start_x <= B.start_x && A.end_x >= B.start_x && B.start_y <= A.start_y && B.end_y >= A.start_y;
}
void findLength(Position &now, Info &target)
{
    if (now_dir == 0)
        result += (target.start_x - now.x);
    else if (now_dir == 1)
        result += (target.start_y - now.y);
    else if (now_dir == 2)
        result += (now.x - target.end_x);
    else
        result += (now.y - target.end_y);
}
bool isRange(Info &now)
{
    return now.start_x >= 0 && now.start_y <= 2 * N && now.start_y >= 0 && now.start_y <= 2 * N;
}
vector<Info> vec;
Position pos;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    pos.y = N, pos.x = N;
    while (M-- > 0)
    {
        int howManyGo;
        char howRotate = 'R';
        cin >> howManyGo >> howRotate;
        int next_x = pos.x + dx[now_dir] * howManyGo;
        int next_y = pos.y + dy[now_dir] * howManyGo;
        Info cur = {pos.x, pos.y, next_x, next_y};
        cur.isColum=pos.y==next_y;
        if (next_x < pos.x)
            swap(cur.start_x, cur.end_x);
        if (next_y < pos.y)
            swap(cur.start_y, cur.end_y);
        if (isRange(cur))
        { //범위 안에있을떄
            for (auto &now : vec)
            {
                if (canGo(cur, now))

                    continue;
                else
                {
                    findLength(pos, now);
                    cout << result;
                    exit(0);
                }
            }
        }
        else
        {
            if (now_dir == 0)
                result += (2 * N - pos.x);
            else if (now_dir == 1)
                result += (2 * N - pos.y);
            else if (now_dir == 2)
                result += pos.x;
            else 
                result += pos.y;
            cout<< result;
            exit(0);
        }
        rotate(howRotate);
        vec.push_back(cur);
        result += howManyGo;
        pos.y = next_y;
        pos.x = next_x;
    }
    cout << result;
    return 0;
}