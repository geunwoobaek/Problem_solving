#include<iostream>
#include<queue>
#include<math.h>
using namespace std;
int N,M;
vector<pair<int,int>> pos;
vector<pair<int,int>> rel;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cin>>N>>M;
pos.resize(N+1);
rel.resize(M+1);
for(int i=0;i<N+1;i++) cin>>pos[i];
return 0;
}