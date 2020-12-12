#include <bits/stdc++.h>
using namespace std;
#define pi pair<long long, int>
#define sum first
#define min_ second
int A[10001];
int cal(pi p) { return p.sum * p.min_; }
pi Division(int from, int to)
{
    if (from == to) return {A[to], A[to]};
    int mid = (from + to) / 2;
    pi left = Division(from, mid);
    pi right = Division(mid + 1, mid);
    pi better = cal(left) > cal(right) ? left : right;
    pi merge = { left.sum + left.sum, min(left.min_, right.min_)};
}
int main()
{
}