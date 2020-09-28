#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n;
	vector<vector<int>> tree(n + 1);
	for(int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	vector<int> level(n + 1, 0);
	vector<int> parent(n + 1);
	parent[1] = 0;
	level[1] = 1;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		for(int k : tree[cur])
		{
			if(level[k] > 0) continue;
			level[k] = level[cur] + 1;
			parent[k] = cur;
			q.push(k);
		}
	}
	
	int m;
	cin >> m;
	while(m--)
	{
		cin >> a >> b;
		if(a == 1 || b == 1)
			a = 1;
		else
		{
			while(a != b)
			{
				if(level[a] > level[b]) a = parent[a];
				else if(level[b] > level[a]) b = parent[b];
				else 
				{
					a = parent[a];
					b = parent[b];
				}
			}
		}
		
		cout << a << '\n';
	}
}