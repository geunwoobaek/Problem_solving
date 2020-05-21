#include<iostream>
using namespace std;

long long a[41];
int main()
{
	int result = 0;
	int n, s; cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < (1 << n); i++)
	{
		long long sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j)) 
            sum += a[j];
		}
		if (sum == s)result++;
	}
	cout << result;
}