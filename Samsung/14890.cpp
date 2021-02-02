#include <bits/stdc++.h>
using namespace std;
#define F(i, j, k) for (int i = j; i <= k; i++)
int N, L;
int Map[101][101];
int bridge_num = 0;
enum
{   down,same,up,no,scan_row,scan_col};
//경사로를 놓으면 길이가 1증가
int state(int before_height, int cur_height)
{
    if (cur_height - before_height > 1 || before_height - cur_height > 1)
        return no;
    else if (cur_height - before_height == 1)
        return up;
    else if (cur_height == before_height)
        return same;
    else
        return down;
}
void process(int mode)
{
    F(col, 1, N) //가로로
    {
        int before_height = mode == scan_row ? Map[col][1] : Map[1][col];
        int count=1;
        F(row, 2, N)
        {   
            int cur_height = mode == scan_row ? Map[col][row] : Map[row][col];
            int now=state(before_height,cur_height);
            if(now==same) count++; 
            else if (now == up && count >= L) count = 1;
            else if (now == down && count >= 0) count = -L+1;
            else {count=-1;break;} 
            before_height=cur_height;
        }
        if (count>=0)
        {    
            bridge_num++;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L;
    F(y, 1, N)
    F(x, 1, N)
    cin >> Map[y][x];
    //가로로 전부다 탐색
    process(scan_row);
    process(scan_col);

    //세로로 전부다 탐색
    cout << bridge_num;
    return 0;
}