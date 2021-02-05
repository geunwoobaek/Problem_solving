#include <bits/stdc++.h>

using namespace std;
//지점갯수 n은 3 이상 200 이하인 자연수입니다. //s첫출발지점 a
#define F(i, j, k) for (int i = j; i <= k; i++)
int floayd[301][301];
int sum=1e9;
int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    F(i, 1, n)
    {
        F(j, 1, n)
        {
            floayd[i][j] = 2e6;
        }
        floayd[i][i] = 0;
    }
    for (auto &fare : fares)
    {
        int from = fare[0];
        int to = fare[1];
        int cost = fare[2];
        floayd[from][to]=cost;
        floayd[to][from]=cost;
    }
    F(path, 1, n)
    {
        F(start, 1, n) 
        {  
            F(to, 1, n) //언젠간 Path를거침
            {
                floayd[start][to]=min(floayd[start][to],floayd[start][path]+floayd[path][to]);
            }
        }
    }
    //sum[t][s]+sum[t][a]+sum[t][b]
    F(path,1,n){
        sum=min(sum,floayd[s][path]+floayd[path][a]+floayd[path][b]);
    }
    return sum;
}
int main()
{
    cout << solution(6, 4, 6, 2, {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}});
    return 0;
}