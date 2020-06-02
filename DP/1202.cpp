#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N,K;
struct info{
    int now,value,weight,bitmask;
};
struct com{
    info operator()(info a,info b)
    {
        if(a.weight>b.weight) return a;
        else return b;
    }
};
vector<pair<int,int>> jewel; //보석
priority_queue<info,vector<info>,com> que; //que
bool visit[100000001];
vector<int> bag;
bool compare(pair<int,int> A,pair<int,int> B){return A.second>B.second;}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL); //입출력속도증가
cin>>N>>K;
jewel.resize(N);
bag.resize(K);
for(int i=0;i<N;i++) cin>>jewel[i].first>>jewel[i].second;
for(int i=0;i<K;i++) cin>>bag[i];
sort(bag.begin(),bag.end());
sort(jewel.begin(),jewel.end(),compare);
while(!que.empty())
{

}
return 0;
}