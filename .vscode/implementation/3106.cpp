#include <bits/stdc++.h>
using namespace std;
int N;
#define Pair pair<int, int>
#define x first
#define y second
struct square
{
    int x1, y1, x2, y2;
};
int cnt = 0;
vector<square> Squares(1, {0, 0, 0, 0});
bool isOverLap(square &s1, square &s2)
{
    square StandardLine[4] = {{s1.x1, s1.y1, s1.x2, s1.y1}, {s1.x1, s1.y1, s1.x1, s1.y2}, {s1.x1, s1.y2, s1.x2, s1.y2}, {s1.x2, s1.y1, s1.x2, s1.y2}}; //비교할기준선들
    square TargetLine[4] = {{s2.x1, s2.y1, s2.x2, s2.y1}, {s2.x1, s2.y1, s2.x1, s2.y2}, {s2.x1, s2.y2, s2.x2, s2.y2}, {s2.x2, s2.y1, s2.x2, s2.y2}};   //비교할기준선들
    for (auto &standard : StandardLine)
    {
        for (auto &target : TargetLine)
        {
            bool xOverRap = (standard.x2 >= target.x1) && (standard.x1 <= target.x2);
            bool yOverRap = (standard.y2 >= target.y1) && (standard.y1 <= target.y2);
            if (xOverRap && yOverRap)
                return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        square cur;
        cin >> cur.x1 >> cur.y1 >> cur.x2 >> cur.y2;
        if (cur.x1 > cur.x2)
            swap(cur.x1, cur.x2);
        if (cur.y1 > cur.y2)
            swap(cur.y1, cur.y2);
        Squares.push_back(cur);
    }
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (j == i)
            {
                if (j == N)
                    cnt++;
                continue;
            }
            if (isOverLap(Squares[i], Squares[j]))
                break;
            else if (j == N)
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}