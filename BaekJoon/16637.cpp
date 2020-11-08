#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, Max=-(1<<31);
string str;
vector<int> num;
vector<char> op;
void dfs(int now, int res);
int cal(int a, char op, int b);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (i % 2 == 0) num.push_back(str[i] - '0');
        else op.push_back(str[i]);
    }
    dfs(0,num[0]);
    cout << Max;
}
void dfs(int now, int res)
{
    if (now >= op.size())
    {
        Max = max(Max, res);
        return;
    }
    dfs(now + 1, cal(res, op[now], num[now + 1])); //현재계산하고 다음으로 넘어가기
    if (now + 2 < num.size()) dfs(now + 2,  cal(res, op[now], cal(num[now + 1], op[now + 1], num[now + 2])));
}
int cal(int a, char op, int b)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    else
        return a * b;
}
