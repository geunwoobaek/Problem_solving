#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <math.h>
#include <memory.h>
#include <set>
using namespace std;

struct ticket {
	int destination;
	int cost;
	int time;
};

int n, m, k;
int dp[101][10001]; // i번 도시까지 j원으로 가는 경우 걸리는 시간
int buf[101][101][2];
vector<ticket> v[101];

int recv(int node, int money) {
	if (money > m) {
		return 1e7;
	}
	if (node == n) {
		return 0;
	}
	int& ret = dp[node][money];
	if (~ret) return ret;
	ret = 1e7;
	for (auto nxt : v[node]) {
		ret = min(ret, recv(nxt.destination, money + nxt.cost) + nxt.time);
	}
	return ret;
}
void solve() {
	memset(dp, -1, sizeof(dp));
	memset(buf, 0, sizeof(buf));
	cin >> n >> m >> k;
	for(int i = 1; i <= n ; i++){
        v[i].clear();
    }
	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		ticket info = { b,c,d };
		v[a].push_back(info);
	}
	int ans = recv(1, 0);
	if (ans >= 1e7 || ans == -1) {
		cout << "Poor KCM";
	}
	else {
		cout << ans;
	}

	cout << "\n";

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (; t--;) {
		solve();
	}
    return 0;
}