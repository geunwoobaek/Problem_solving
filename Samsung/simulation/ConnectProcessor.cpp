#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int Map[12][12];
int Max = 2e9;
int MaxCount=0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int N, vector<pair<int, int>> &core, int now, int result,int cnt)
{
    if (now == core.size())
    {   if(cnt>MaxCount) 
        {   
            MaxCount=cnt;
            Max = result;
        }
        else if(cnt==MaxCount)
        {
            Max=Max>result?result:Max;
        }
        return;
    }
    int y = core[now].first;
    int x = core[now].second;
    bool on=false;
    for (int i = 0; i < 4; i++)
    {
        pair<int, int> next = {y, x};
        bool istrue = true;
        int sum = 0;
        while (next.first > 0 && next.second > 0 && next.first < N - 1 && next.second < N - 1)
        {
            sum++;
            next.first += dy[i];
            next.second += dx[i];
            if (Map[next.first][next.second] == 1)
            {
                istrue = false;
                break;
            }
            Map[next.first][next.second] = 1;
        }
        if (istrue)
        {   on=true;
            dfs(N, core, now + 1, result + sum,cnt+1);
            Map[next.first][next.second]=0;
        }
        while (next != make_pair(y, x))
        {
            next.first -= dy[i];
            next.second -= dx[i];
            Map[next.first][next.second] = 0;
        }
        Map[y][x] = 1;
    }
    if(!on){
         dfs(N, core, now + 1, result,cnt);
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

	 memset(Map, sizeof Map, 0);
        Max = 2e9;
        MaxCount=0;
         int N;
        cin >> N;
        vector<pair<int, int>> Core;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> Map[i][j];
                if (Map[i][j] == 1 && i != 0 && i != N - 1 && j != 0 && j != N - 1)
                {
                    Core.push_back({i, j});
                }
            }
        }
        dfs(N, Core, 0, 0,0);
        cout <<"#"<<test_case<<" "<<Max << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}