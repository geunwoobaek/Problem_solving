#include <iostream>
#include <vector>
using namespace std;
int N;
#define Pair pair<int,int>
vector<int> vec; //first=value,second=count;
int dp[100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vec.resize(N);
    for (int i = 0;i < N;i++)
    {
        cin >> vec[i];
    }
    for(int i=0;i<N;i++)
    {
        int now=vec[i];
        for(int j=i+1;j<N;j++)
        {
           if(now<vec[j])
           {
               dp[j]=dp[i]+1;
           }
        }
    }
    cout<<dp[1];
    return 0;
}
