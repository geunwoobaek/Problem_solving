#include <bits/stdc++.h>
using namespace std;
bool arr[4];
unordered_map<char, int> cnt_map;
bool length_condition(string &str)
{
    return !(((int)str.length()) >= 8 && ((int)str.length()) <= 15);
}
bool not_include_condition(string &str)
{
    for (auto &one : str)
    {
        if ((one >= 'A' && one <= 'Z') || (one >= 'a' && one <= 'z') || (one >= '0' && one <= '9') || (one >= '`' && one <= '*'))
            continue;
        else
            return true;
    }
    return false;
}
bool include_condition(string &str)
{
    for (auto &one : str)
    {
        if (one >= 'A' && one <= 'Z')
            arr[0] = true;
        else if (one >= 'a' && one <= 'z')
            arr[1] = true;
        else if (one >= '0' && one <= '9')
            arr[2] = true;
        else if (one >= '`' && one <= '*')
            arr[3] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        if (arr[i])
            cnt++;
    }
    return cnt < 3;
}
int continue_condition(string str)
{
    sort(str.begin(), str.end());
    int cnt = 1;
    int max_cnt = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i] == str[i - 1])
            cnt++;
        else
            cnt = 1;
        max_cnt = max(max_cnt, cnt);
    }
    return max_cnt;
}
bool overrap_condition(string &str)
{
    for (auto &c : str)
    {   
        cnt_map[c]++;
        if(cnt_map[c]>=5) return true;
    }
    return false;
}
vector<int> solution(string inp_str)
{
    vector<int> answer;
    if (length_condition(inp_str))
        answer.push_back(1);
    if (not_include_condition(inp_str))
        answer.push_back(2);
    if (include_condition(inp_str))
        answer.push_back(3);
    int max_cnt = continue_condition(inp_str);
    if (max_cnt >= 4) answer.push_back(4);
    if(overrap_condition(inp_str)) answer.push_back(5);
    if (answer.size() == 0)  answer.push_back(0);
    return answer;
}