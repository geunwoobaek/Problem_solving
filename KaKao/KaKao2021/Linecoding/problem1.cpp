#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
using namespace std;
vector<int> now;
struct compare
{
    bool operator()(int a, int b)
    {
        if (a == now.back() || a == now[0] || b == now[0] || b == now.back())
            return false;
        else
            return true;
    }
};
vector<int> solution(vector<int> ball, vector<int> order)
{
    vector<int> answer(ball.size());
    int it = 0;
    while (order.size() != 0)
    {
        for (int i = 0; i < order.size(); i++)
        {
            if (order[i] == ball.back())
            {
                answer[it++] = order[i];
                order.erase(order.begin() + i, order.begin() + i + 1);
                ball.pop_back();
                break;
            }
            else if (order[i] == ball.front())
            {
                answer[it++] = order[i];
                order.erase(order.begin() + i, order.begin() + i + 1);
                ball.erase(ball.begin(), ball.begin() + 1);
                break;
            }
        }
    }

    return answer;
}
int main()
{
}