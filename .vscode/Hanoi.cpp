#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
#define f(i,j,k) for(int i=j;i<=k;i++)
int N, G;
vector<vector<int>> tower(4);
void input();
void solve();
int main()
{
    solve();
}
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> G;
    f(i,1,3)
    {
        int t;
        cin >> t;
        tower[i].resize(t);
        f(j,0,t-1)
        {
            cin>>tower[i][j];
        }
    }
}
void solve(){
    input();
    cout<<"";
}