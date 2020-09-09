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
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
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