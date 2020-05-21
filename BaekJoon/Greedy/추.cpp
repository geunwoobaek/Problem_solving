#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define max 1000000
int Map[1000];
int DP[1000];
int N,Sum=1;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++) cin>>Map[i];
    sort(Map,Map+N);
    for(int i=0;i<N;i++)
    {
        if(Map[i]>Sum) break;
        else Sum+=Map[i];
    }
    cout<<Sum;
    return 0;
}