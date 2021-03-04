#include <bits/stdc++.h>
#define LIMIT_ 30001
#define F(i, s, e) for (int i = s; i <= e; i++)
using namespace std;
int TestCase, N, W;
vector<int> cache1, cache2;
vector<int> vec1, vec2;
bool visit[LIMIT_];
int dp(vector<int> &vec, vector<int> &cache, int idx)
{
    if (idx > 2 * N)
        return 0;
    if (visit[idx])
        return dp(vec, cache, idx + 1);
    visit[idx] = true;
    int &result = cache[idx];
    if (result != 2e9)
        return result;
    else
        result = 2e9;
    bool canRight = (idx % N != 0) && !visit[idx + 1] && (vec[idx] + vec[idx + 1]) <= W;
    bool canBottom = (idx <= N) && !visit[idx + N] && (vec[idx] + vec[idx + N]) <= W;
    if (canRight) //오른쪽 탐색가능
    {
        cout << "오른쪽 처리 idx=" << idx << "\n";
        visit[idx + 1] = true;
        result = 1 + dp(vec, cache, idx + 2);
        // cout<<"오른쪽 처리 결과:"<<result<<"\n";
        visit[idx + 1] = false;
    }
    if (canBottom) //밑 탐색가능
    {
        cout << "밑 처리 idx=" << idx << "\n";
        visit[idx + N] = true;
        result = min(result, 1 + dp(vec, cache, idx + 1));
        // cout<<"밑 처리 결과:"<<result<<"\n";
        visit[idx + N] = false;
    }
    if (!canRight && !canBottom)
    {
        cout << "한칸처리 idx=" << idx << "\n";
        result = 1 + dp(vec, cache, idx + 1);
//         cout<<"한칸처리 결과:"<<result<<"\n";
    }
    visit[idx] = false;
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> TestCase;
    while (TestCase--)
    {
        memset(visit, false, sizeof visit);
        cin >> N >> W;
        cache1.resize(2 * N + 1, 2e9);
        cache2 = cache1;
        vec1.resize(2 * N + 1);
        F(i, 1, 2 * N)
        {
            cin >> vec1[i];
        }
        vec2 = vec1;
        vec2.erase(vec2.begin() + 1);
        vec2.insert(vec2.begin() + N, vec1[1]);
        vec2.erase(vec2.begin() + N + 1);
        vec2.push_back(vec1[N + 1]);

        int result = dp(vec1, cache1, 1);
         cout << result << "\n";
        memset(visit, false, sizeof visit);
        cout << min(result, dp(vec2, cache2, 1)) << "\n";

        vec1.clear();
        vec2.clear();
        cache1.clear();
        cache2.clear();
    }
    return 0;
}
