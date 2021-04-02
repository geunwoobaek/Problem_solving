#include <bits/stdc++.h>
using namespace std;

unordered_map<char, bool> words;
unordered_map<char, int> cur;
bool isSuccess()
{
    return cur['p'] >= 1 && cur['r'] >= 3 && cur['o'] >= 1 && cur['g'] >= 1 && cur['m'] >= 2 && cur['e'] >= 1 && cur['a'] >= 1;
}
int programmerStrings(string s)
{
    words['p'] = true;
    words['r'] = true;
    words['o'] = true;
    words['g'] = true;
    words['r'] = true;
    words['a'] = true;
    words['m'] = true;
    words['e'] = true;
    words['r'] = true;
    int answer = 0;
    int programmer_size = 0; //홀수이면 중간문자열로 인식
    for (int i = 0; i < s.size(); i++)
    {
        auto &one = s[i];
        if (programmer_size % 2 == 1 && cur.empty())
        {
            if (words[one])
            {
                continue;
            }
            else
            { //더하는 순간 words[one]의 문자가 오면 바로 다음모드
                answer++;
            }
        }
        else
        {
            cur[one]++;
            if (isSuccess())
            {
                cur.clear();
                programmer_size++;
            }
        }
    }
    return answer;
}
int main()
{
    programmerStrings("xprogxrmaxemrppprmmograeiruu");
    return 0;
}
