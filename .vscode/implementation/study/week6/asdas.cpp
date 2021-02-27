#include <stdio.h>
using namespace std;
 
#define mod 1000000000
 
int n, i, j, k, ans;
int dp[101][10][1 << 10];
 
int main() {
    scanf("%d", &n);
 
    int full = (1 << 10) - 1;
 
    for (j = 1; j <= 9; ++j)
        dp[1][j][1 << j] = 1;
 
    for (i = 2; i <= n; ++i) {
        for (j = 0; j <= 9; ++j) {
            for (k = 0; k <= full; ++k) {
                if (j == 0)
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
                else {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
                }
            }
        }
    }
 
    for (j = 0; j <= 9; ++j)
        ans = (ans + dp[n][j][full]) % mod;
 
    printf("%d", ans);
 
    return 0;
}
