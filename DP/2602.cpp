#include <bits/stdc++.h>
using namespace std;
string pattern;
string n1, n2;
//__AABBCC
int Bridge_length;
int cache[201][21];
char bridge[202];
int dp(int cursor, int matching)
{   
    if (matching == pattern.length()) return 1;
    if (((Bridge_length - cursor) < (int(pattern.length()) - matching)))
    { return 0;}
    int& result = cache[cursor][matching];
    if (result != -1) return result;
    result = 0;
    if (bridge[cursor] == pattern[matching]) {
        int nextpoint = cursor&1 ? 1 : 3;
        result += dp(cursor + nextpoint, matching + 1);
    }
    result += dp(cursor + 2, matching);
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> pattern >> n1 >> n2;
    int i = 0, j = 0, k = 0;
    Bridge_length = (n1.length()) * 2;
    while (i < n1.length())
    {
        bridge[k] = n1[i++];
        k += 2;
    }
    k = 1;
    while (j < n2.length())
    {
        bridge[k] = n2[j++];
        k += 2;
    }
    for (int i = 0;i < 201;i++) for (int j = 0;j < 21;j++) cache[i][j] = -1;
    cout << dp(0, 0)+ dp(1, 0);
    
    return 0;
}