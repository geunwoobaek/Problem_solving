#include <bits/stdc++.h>
using namespace std;
int N, res;
int p[2002][2002];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

void dfs(int x, int y) {
	p[x][y] = 2;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx>2000 || ny>2000) continue;
		if (p[nx][ny] == 0 || p[nx][ny] == 2) continue;
		dfs(nx, ny);
	}
}
int main()
{
	cin >> N;
	int x1, y1, x2, y2;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		x1 = (x1 + 500) * 2;
		y1 = (y1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y2 = (y2 + 500) * 2;
		for (int j = y1; j <= y2; j++) 
			p[x1][j] = p[x2][j] = 1;
		for (int j = x1; j <= x2; j++)
			p[j][y1] = p[j][y2] = 1;
	}

	for (int i = 0; i <= 2000; i++) {
		for (int j = 0; j <= 2000; j++) {
			if (p[i][j] == 1) {
				res++;
				dfs(i, j);
			}
		}
	}

	if (p[1000][1000] == 2) res--; 
	cout << res;
}