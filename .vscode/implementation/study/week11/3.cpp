#include <bits/stdc++.h>
using namespace std;

int combination(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    else
        return combination(n - 1, r - 1) + combination(n - 1, r);
}
int countTeams(vector<int> skills, int minPlayers, int minLevel, int maxLevel)
{
    sort(skills.begin(), skills.end());
    int start_idx = lower_bound(skills.begin(), skills.end(), minLevel) - skills.begin();
    int end_idx = lower_bound(skills.begin(), skills.end(), maxLevel) - skills.begin();
    if (end_idx==skills.size()||skills[end_idx] > maxLevel)
        end_idx--;
    int totalNumber = end_idx - start_idx + 1;
    int res = 0;
    for (int i = minPlayers; i <= totalNumber; i++)
        res += combination(totalNumber, i);
    return res;
}

int main()
{
countTeams(
{248,
779,
392,
727,
561},2,360,1000);
return 0;
}