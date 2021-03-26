#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int, long long>
#define pos first
#define times second
#define ll long long
struct compare
{
    bool operator()(Pair a, Pair b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};
priority_queue<Pair, vector<Pair>, compare> que;
vector<int> solution(int N, vector<int> coffee_times)
{
    vector<int> answer;
    ll time = 0;
    for (int i = 0; i < coffee_times.size(); i++)
    {
        que.push({i, time + coffee_times[i]});
        if (que.size() != N)
            continue;
        else
        {
            ll now = que.top().second;
            while (!que.empty() && que.top().times == now)
            {
                Pair cur = que.top();
                que.pop();
                answer.push_back(cur.pos + 1);
            }
            time = now;
        }
    }
    while (!que.empty())
    {
        Pair cur = que.top();
        que.pop();
        answer.push_back(cur.pos + 1);
    }
    return answer;
}
int main()
{
    vector<int> coffee = {3,2,1,3,4,5,8,1};
    solution(2, coffee);
    return 0;
}