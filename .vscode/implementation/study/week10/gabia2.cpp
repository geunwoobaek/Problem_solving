#include <bits/stdc++.h>
using namespace std;
#define Pair pair<int, int>
#define pos first
#define value second;
unordered_map<string, bool> umap;
map<Pair, int> cache;                               //pos
int dfs(int num, int pos, string &cur, string &str) //만약에 지금 나오
{
    if (pos == (int)str.size())
        return 0;
    umap[cur] = true;
    int now_num = 1 << (str[pos] - 'a');
    Pair now = {pos, num};
    if (cache.find(now) != cache.end())
    {
        return cache[now];
    }
    else
    {
        int &result = cache[now];
        if ((now_num & num) == 0)
        {
            cur.push_back(str[pos]);
            if (!umap[cur]) result += 1;
            result = dfs((now_num + num), pos + 1, cur, str);
        }
        cur = "";
        cur.push_back(str[pos]);
        if (!umap[cur]) result += 1;
        result += dfs(now_num, pos + 1, cur, str);
        return result;
    }
}
int solution(string s) //연속부분문자열 갯수구하는문제 cache[i]=dfs(i+1,now_num)+dfs(i+1,0);
{
    string init_str = "";
    int answer = 0;
    answer += dfs(0, 0, init_str, s);
    return umap.size()-1;
}
int main()
{
    string str = "a";
    cout << solution("asddfavfdsasd");
    return 0;
}