#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int sizeofbitmask = 0;
int MaxLength = 0; //n의 길이
int Minimum_Result = 2e9;
struct info
{
    int distance;
    int size;
    vector<int> weak;
};
vector<info> vec;
void dfs(vector<int>& weak, vector<int>& dist, int now_cache, int depth)
{
    if (depth >= Minimum_Result) return;
    if (now_cache == sizeofbitmask)
    {
        if (Minimum_Result > depth)
            Minimum_Result = depth;
        return;
    }
    else if (dist.size() == depth) return;
    int maxnum = 0;
    for (int i = 0; i < weak.size(); i++)
    {
        int current_length = dist[depth];
        int current_cache = now_cache;
        if ((current_cache & (1 << i))==1) continue;
        int j = i;
        int start = weak[i];
        current_cache |=(1 << i);
        int nownum = 0;
        while (current_length > 0)
        {
            j++;
            if (j == weak.size())
            {
                j = 0;
                current_length -= (MaxLength - weak.back());
                start = 0;
            }
            else start = weak[j - 1];
            current_length -=(weak[j]- start);
            if (current_length < 0) break;
            int visit = 1 << j;
            int temp;
            temp=current_cache | visit;
            if (temp != current_cache)
            {
                current_cache = temp; 
                nownum++;
            }
        }
        if (nownum < maxnum) continue;
        maxnum = nownum;
        dfs(weak, dist, current_cache, depth + 1);
    }
}
int solution(int n, vector<int> weak, vector<int> dist)
{
    sizeofbitmask = (1 << weak.size()) - 1;
    MaxLength = n;
    sort(dist.begin(), dist.end(), greater<int>());
    dfs(weak, dist, 0, 0);
    if (Minimum_Result == 2e9)
        return -1;
    else
        return Minimum_Result;
}

int main()
{
    int n = 12;
    vector<int> weak;
    vector<int> dist;
    weak.push_back(1);
    weak.push_back(5);
    weak.push_back(6);
    weak.push_back(10);
    dist.push_back(1);
    dist.push_back(2);
    dist.push_back(3);
    dist.push_back(4);
    cout << solution(n, weak, dist);
    return 0;
}