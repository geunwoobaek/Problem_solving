#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MaxNum=10000000L;
int findGmax(ll begin)
{ //begin보다 작은 가장큰약수 구하기
    for (ll i=begin-1>MaxNum?MaxNum:begin-1;i>0; i--)
    {
        if (begin % i == 0) return i;
    }
    return 1;
}
vector<int> solution(long long begin, long long end)
{
    vector<int> answer;
    if (begin == 1)
    {
        answer.push_back(0);
        begin++;
    }
    for (; begin <= end; begin++)
    {
        answer.push_back(findGmax(begin));
    }
    return answer;
}
int main()
{
    solution(1, 10);
}