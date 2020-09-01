#include <cstdio>
#include <vector>
using namespace std;

int n, ccnt[10001];
long long d[50005];
vector<int> cvec;
bool p[50005];

void getprimes() {
	for (int i = 2; i <= 50000; i++) p[i] = 1;
	for (int i = 2; i*i <= 50000; i++)
		if (p[i]) for (int j = i*i; j <= 50000; j += i)
			p[j] = 0;
}

int main() {
	getprimes();
    return 0;
}