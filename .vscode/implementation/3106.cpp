#include <bits/stdc++.h>
using namespace std;
int N;
struct square
{
    int x1, y1, x2, y2;
};
int cnt = 0;
vector<square> Squares(1, {0, 0, 0, 0});
bool isOverap(square &s1, square &s2)
{
    return ((s1.x2 >= s2.x1) && (s2.x2 >= s1.x1)) && ((s1.y2 >= s2.y1) && (s2.y2 >= s1.y1));
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
        cin >> cur.x1 >> cur.x2 >> cur.y1 >> cur.y2;
        if (cur.x1 > cur.x2)
            swap(cur.x1, cur.x2);
        if (cur.y1 > cur.y2)
            swap(cur.y1, cur.y2);
        Squares.push_back(cur);
    }
    for (int i = 0; i <= N; i++)
    {
        int j = 0;
        for (; j <= N; j++)
        {
            if (j == i)
                continue;
            if (isOverap(Squares[i], Squares[j]))
                break;
        }
        if (j > N) cnt++;
    }
    cout << cnt;
    return 0;
}