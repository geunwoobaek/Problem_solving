#include <bits/stdc++.h>
#define Point vector<int>
#define LL long long
#define y 0
#define x 1
using namespace std;
LL Max = 2e15;
unordered_map<LL, int> um;
unordered_map<LL, bool> check;
int max_count = 0;
//y=ax+b //점두개주면 그거바탕으로 직선의 방정식 만들기
void MakeLine(Point &a, Point &b)
{ //모든 좀의 조합으로 N*(N-1) 직선의 방정식 만들기 HashMap x=1일때
    //y=((y2-y1)/(x2-x1)*(x-x1)+y1
    LL now = Max;
    if (a[x] != b[x])
    {
        now = (1e6 - a[x]) * (a[y] - b[y]) / (a[x] - b[x]) + a[y];
        if (check[now]) return;
            um[now]++;
    }
    else if (!check[now])
        um[now]++;
    max_count = max(max_count, um[now]);
}
int maxPoints(vector<Point> &points)
{
    max_count = 0;
    um.clear();
    check.clear();
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
            MakeLine(points[i], points[j]);
        for (auto &key : um)
            check[key.first] = true;
    }
    return max_count+1;
}
int main()
{
    vector<Point> points({{1, 0}, {0, 0}});
    maxPoints(points);
}
