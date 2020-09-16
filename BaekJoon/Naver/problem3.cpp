#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
int num = 1234567890;
using namespace std;
string str;
int dp[200000];
void process()
{
}
int solution(vector<int> &blocks)
{   memset(dp,sizeof dp,0);
    int maximum=0;
    int index = 0;
    for (int i = 0; i < blocks.size() - 1; i++)
    {
        if (blocks[i] <= blocks[i + 1])
            dp[index]++;
        else
            index = i + 1;
    }
    index = blocks.size() - 1;
    for (int i = blocks.size() - 1; i >= 1; i--)
    {
        if (blocks[i] <= blocks[i - 1])
            dp[index]++;
        else
            index = i - 1;
    }
    for(int i=0;i<blocks.size();i++)
    {
        maximum=max(maximum,dp[i]);
    }
    return maximum+1;
}
int main()
{
    cout << num;
}