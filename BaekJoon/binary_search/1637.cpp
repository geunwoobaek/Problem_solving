#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#define f ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
long long MIN = 2147483647;
long long MAX = 0;
long long answer, answer1, answer2;
vector<pair<long long, pair< long long, long long>>>v;
int main() {
	f;
	int n; cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		long long a, b, c; cin >> a >> b >> c;
		v.push_back({ c,{a,b} });
		sum += (b - a) / c + 1;
		MIN = min(MIN, a);
		MAX = max(MAX, b);
	}
	if (sum % 2 == 0) {
		cout << "NOTHING";
		return 0;
	}
	long long start = MIN;
	long long end = MAX;
	while (start <= end) {
		long long mid = (start + end) / 2; long long all = 0;
		for (int i = 0; i < v.size(); i++) {
			long long b = v[i].second.second; long long a = v[i].second.first; long long c = v[i].first;
			if (b <= mid)all += (b - a) / c + 1;
			if (mid >= a && b > mid)all += (mid - a) / c + 1;
		}
		if (all % 2 == 0) {
			start = mid +1;
			answer2 = all;
		}
		else {
			end = mid ;
			answer = mid;
			answer1 = abs(all - answer2);
			if (start == end)break;
		}
	}
	cout << answer << " " << answer1;
}