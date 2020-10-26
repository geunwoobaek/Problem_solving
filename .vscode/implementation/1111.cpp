// IQ Test의 문제 중에는 공통된 패턴을 찾는 문제가 있다. 수열이 주어졌을 때, 다음 수를 찾는 문제이다.
// 예를 들어, 1, 2, 3, 4, 5가 주어졌다. 다음 수는 무엇인가? 당연히 답은 6이다. 약간 더 어려운 문제를 보면, 3, 6, 12, 24, 48이 주어졌을 때, 다음 수는 무엇인가? 역시 답은 96이다.
// 이제 제일 어려운 문제를 보자.
// 1, 4, 13, 40이 주어졌을 때, 다음 수는 무엇일까? 답은 121이다. 그 이유는 항상 다음 수는 앞 수*3+1이기 때문이다.
// 은진이는 위의 3문제를 모두 풀지 못했으므로, 자동으로 풀어주는 프로그램을 작성하기로 했다. 항상 모든 답은 구하는 규칙은 앞 수*a + b이다. 그리고, a와 b는 정수이다.
// 수 N개가 주어졌을 때, 규칙에 맞는 다음 수를 구하는 프로그램을 작성하시오.
//*a + b
//100보다
//-100<x<100;
// 1, 4, 13,40 a
// 입력 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N,a,b,cnt=0;
long answer=2e12;//a=곱하는것 b=더하는것
vector<int> vec;
int main()
{
ios_base::sync_with_stdio(false);
cin>>N;
vec.resize(N);
for(int i=0;i<N;i++) cin>>vec[i];
for(a=10000000;a>=-10000000&&cnt<2;a--)
{
    b=vec[1]-vec[0]*a;
    int i=1;
    if(a==0)
    cout<<"";
    for(;N;i++)
    {
        if(vec[i-1]*a+b!=vec[i])
            break;
    }
    if(i==N&&answer!=vec[N-1]*a+b) {
        cnt++;
        answer=vec[N-1]*a+b;
    }

}
if(cnt==2) cout<<"A";
else if(cnt==1) cout<<answer;
else cout<<"B";
return 0;
}