#include<iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
int cache[501][501];
int maximum = 2e9;
int dp(vector<vector<int>>& triangle, int height, int pos, int now)
{
    now += triangle[height][pos];
    if (maximum < now) return 0;
    if (height == triangle.size())
    {
        return now;
    }
    int& result = cache[height][pos];
    if (result != -1) return now;
    result = now;
    return result += max(dp(triangle, height + 1, pos, now), dp(triangle, height + 1, pos + 1, now));
}
int solution(vector<vector<int>> triangle)
{
    memset(cache, -1, sizeof(cache));
    int answer = dp(triangle, 0, 0, 0);
    return answer;
}