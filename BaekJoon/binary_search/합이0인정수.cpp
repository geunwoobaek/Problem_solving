#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
long long cnt=0;
vector<int>A(4000),B(4000),C(4000),D(4000);
vector<int>Sum1,Sum2;
int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL);
cin>>N;
for(int i=0;i<N;i++)
{
cin>>A[i]>>B[i]>>C[i]>>D[i];
}
for(int i=0;i<N;i++)
{
    for(int j=0;j<N;j++)
    {
        Sum1.push_back(A[i]+B[j]);
        Sum2.push_back(C[i]+D[j]);
    }
}
sort(Sum1.begin(),Sum1.end());
sort(Sum2.begin(),Sum2.end());
for(auto i:Sum1)
{   
    long long Up=upper_bound(Sum2.begin(),Sum2.end(),-i)-Sum2.begin();
    long long Down=lower_bound(Sum2.begin(),Sum2.end(),-i)-Sum2.begin();
    cnt+=Up-Down;
}
cout<<cnt;
return 0;
}
