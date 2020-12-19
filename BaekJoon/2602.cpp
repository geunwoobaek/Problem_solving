#include <bits/stdc++.h>
using namespace std;
string pattern;
string n1, n2;
int pattern_length;
int Bridge_length;
int cache[201][21];
char bridge[202];
int dp(int cursor, int matching)
{
    if (cursor >= Bridge_length)
        return 0;
    int &result = cache[cursor][matching];
    if (result != -1)
        return result;
    result = 0;
    int next=cursor+2;
    int ifmatching=(bridge[next]==pattern[matching]);
    return result=(dp(next,matching)+dp(next+ifmatching,matching+ifmatching));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> pattern >> n1 >> n2;
    int i = 0, j = 0,k=0;
    Bridge_length=(n1.length()+1)*2;
    while (i < n1.length())
    {   
        bridge[2+k] = n1[i++];
        k+=2;
    }
    k=1;
    while (j < n2.length())
    {
        bridge[2+k] = n2[j++];
        k+=2;
    }
    memset(cache,sizeof cache,-1);
    cout<< dp(0,0)+dp(1,0);
    return 0;
}