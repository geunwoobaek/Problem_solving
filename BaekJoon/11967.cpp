#include <iostream>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;

struct Que {
	int x;
	int y;
};

//Que board[101][101][20001];

vector<Que> board[101][101];
bool light[101][101];
bool vis[101][101];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main()
{
	int N, M;
	int a, b, c, d;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
		board[a - 1][b - 1].push_back({c-1,d-1});
	}

	while (1) {
		memset(vis, false, sizeof(vis));//cstring헤터 필요 vis를 초기화
		queue<Que> Q;
		Q.push({ 0,0 });//(0,0)부터 시작하기 때문에
		vis[0][0] = true;
		light[0][0] = true;//불 계속켜주는건 비효율이지만 어쩔수없음
		bool flag = false;
		while (!Q.empty()) {
			auto cur = Q.front();
			Q.pop();
			if (!board[cur.x][cur.y].empty()) {
				for (int i = 0; i < board[cur.x][cur.y].size(); i++) {
					auto c = board[cur.x][cur.y][i];
					light[c.x][c.y] = true;
				}//불을 켜준다.
				board[cur.x][cur.y].clear();//불을 켜준뒤 벡터에 남아있는거 없앤다.
				flag = true;//새로운방에 불을 켰다는 의미
			}

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];

				if (nx<0 && nx>N - 1 or ny<0 or ny>N - 1)continue;
				if (light[nx][ny] == true and vis[nx][ny] == false) {
					Q.push({ nx,ny });
					vis[nx][ny] = true;
				}
			}//상하좌우 돌면서 불켜진방 탐색
		}
		if (!flag) {
			break;
		}//새롭게 불켜진방이없으면 break
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (light[i][j])cnt++;
		}
	}//불켜진방 갯수 세보자.
	cout << cnt << endl;
}