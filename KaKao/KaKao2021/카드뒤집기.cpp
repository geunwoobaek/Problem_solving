#include <bits/stdc++.h>

using namespace std;
#define F(i, j, k) for (int i = j; i < k; i++)
int cnt = 0;
struct Dir{
	int y[4]={-1,1,0,0};
	int x[4]={0,0,1,-1};
} dir;
struct Pos
{
	int y, x;
};
struct Block
{
	int number;
	Pos pos;
};
struct Blocks
{
	Pos A, B;
};
int sum = 0;
int totalNumber;
vector<Block> block;
vector<Blocks> blocks;
bool compare(Block a, Block b) { return a.number < b.number; }
int findGraph(int cache[][6]){
 
}
int getDjstra(Pos from, Pos to) //B
{
	int cache[6][6];
	F(i, 0, 6)
	{
		F(j, 0, 6)
			cache[i][j] = 1e9;
		cache[i][i] = 0;
	}
	findGraph(cache);
	priority_queue<Pos, vector<Pos>> que;
	que.push(from);
	while(!que.empty()){
		Pos cur=que.top();
		que.pop();
		F(i,0,totalNumber){
			min()
		}
	}
}
int dfs(Pos cur, int depth)
{
	if (depth == blocks.size()) return 0;
	Blocks &next = blocks[depth];
	//현재위치에서 A로갔다가 B로갔다가 그다음지점가기 vs 현재위치에서 B로갔다가 A로갔다가 그다음지점가기
	return min(getDjstra(cur, next.A) + getDjstra(next.A, next.B) + dfs(next.B, depth + 1),
			   getDjstra(cur, next.B) + getDjstra(next.B, next.A) + dfs(next.A, depth + 1));
}
int solution(vector<vector<int>> board, int r, int c)
{
	int answer = 2e9;
	F(y, 0, board.size())
	F(x, 0, board.size())
	{
		int num = board[y][x];
		if (num != 0)
			block.push_back({num, y, x});
	}
	sort(block.begin(), block.end(), compare); //2.정렬부분 number별로 나누기위해서
	for (int i = 0; i < block.size(); i += 2) //3.block합치기
	{
		blocks.push_back({block[i].pos, block[i + 1].pos});
	}
	totalNumber=blocks.size();
	do //4. 순열부분 순열적으로 탐색하기위해서
	{
		answer = max(answer, dfs({r,c},0));
	} while (next_permutation(blocks.begin(), blocks.end()));

	return answer;
}