#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 50001
using namespace std;


vector<int> vec[MAX];
int parent[MAX];
int depth[MAX];
bool visited[MAX];

void dfs(int parentNode, int currentDepth){
	depth[parentNode]=currentDepth++;
	for(int nextNode : vec[parentNode]){
		if(!depth[nextNode]) {
			parent[nextNode]=parentNode;
			dfs(nextNode, currentDepth);	
		}
	}
}

void bfs(int parentNode, int currentDepth){
	queue<int> q;
	q.push(parentNode);
	while(!q.empty()){
		int qs=q.size();
		while(qs--){
			int currentNode=q.front();
			depth[currentNode]=currentDepth;
			q.pop();
			for(int nextNode : vec[currentNode]){
				if(!depth[nextNode]){
					parent[nextNode]=currentNode;
					q.push(nextNode);
				}
			}
		}
		currentDepth++;
	}
}

int main(){
	int n, m;
	cin >> n;
    
    // 트리 구성
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	
    // bfs 혹은 dfs를 통해 부모노드와 깊이를 찾는다
//	dfs(1,1);
	bfs(1,1);
	
	cin >> m;
	
	for(int i=0; i<m; i++){
		int c, d;
		cin >> c >> d;
		if(depth[c]<depth[d]) swap(c,d);
		while(depth[c]!=depth[d]) c=parent[c];
		while(c!=d) c=parent[c], d=parent[d];
		cout << c << endl;
	}
	
	return 0;
}