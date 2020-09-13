#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int N;
int MaxCache[30];
map<int, vector<string>> MaXCacheMap;
map<string,bool> visitcache;
void dfs(map<string, int> &m, string current, int start, string &str, int limit, map<string, bool> &check)
{
    if (current.size() > limit)
        return;
    if (current.size() >= 2 && m[current] >= MaxCache[current.size()])
    {   
        if (m[current] > MaxCache[current.size()])
        {   
            MaxCache[current.size()]++;
            vector<string> &c=MaXCacheMap[current.size()];
            for(auto ac:c)
            {
                visitcache[ac]=false;
            }
            c.clear();
        }
        if(visitcache[current]!=true)
        {
            MaXCacheMap[current.size()].push_back(current);
            visitcache[current]=true;
        }
    }
    if (start == str.size())
        return;
    for (int i = start; i < str.size(); i++)
    {
        string cur = current;
        cur.push_back(str[i]);
        if (cur.size() >= 2 && !check[cur])
        {
            m[cur]++;
            check[cur] = true;
        }
        dfs(m, cur, i + 1, str, limit, check);
        dfs(m, current, i + 1, str, limit, check);
    }
}
vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    map<string, int> order_map;
    memset(MaxCache, sizeof MaxCache, 0);
    int limit = course.back();
    for (int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
        map<string, bool> check;
        dfs(order_map, "", 0, orders[i], limit, check);
    }
    map<int, vector<string>>::iterator it = MaXCacheMap.begin();
    vector<int>::iterator course_it = course.begin();
    while (it != MaXCacheMap.end())
    {
        if (*course_it > (*it).first)
            {
                it++;
                continue;
            }
        vector<string> &now =(*it).second;
        it++;
        course_it++;
        if(order_map[now.back()]<2){continue;}
        sort(now.begin(),now.end());
        for(int index=0;index<now.size();index++)
        {
            answer.push_back(now[index]);
        }
    }
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++)
    {
        cout<<answer[i]<<endl;
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> course;
    vector<string> order;
    order.push_back("ABCFG");
    order.push_back("AC");
    order.push_back("CDE");
    order.push_back("ACDE");
    order.push_back("BCFG");
    order.push_back("ACDEH");
    course.push_back(2);
    course.push_back(3);
    course.push_back(4);
    solution(order, course);
    return 0;
}