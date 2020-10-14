/*
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	3125	750	509	23.370%
문제
서로 다른 정수로 이루어진 집합이 있다. 이 집합의 순열을 합치면 큰 정수 하나를 만들 수 있다. 예를 들어, {5221,40,1,58,9}로 5221401589를 만들 수 있다.
 합친수가 정수 K로 나누어 떨어지는 순열을 구하는 프로그램을 작성하시오.
박성원이 우연히 정답을 맞출 확률을 분수로 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 집합의 수의 개수 N이 주어진다. N은 15보다 작거나 같은 자연수이다. 
둘째 줄부터 N개의 줄에는 집합에 포함된 수가 주어진다. 
각 수의 길이는 길어야 50인 자연수이다. 마지막 줄에는 K가 주어진다. K는 100보다 작거나 같은 자연수이다.
출력
첫째 줄에 정답을 기약분수 형태로 출력한다.
 p/q꼴로 출력하며, p는 분자, q는 분모이다. 정답이 0인 경우는 0/1로, 1인 경우는 1/1로 출력한다.
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
int n, k;
ll dp[1 << 15][111];
string s[22];
int arr[22], len[22];
int pw[55];
ll gcd(ll a, ll b){ return a%b==0?b:gcd(b,a%b);}
ll f(int bit, int md){
    ll &res = dp[bit][md];
    if(res != -1) return res;
    if(bit + 1 == 1 << n){
        if(md) return res = 0;
        else return res = 1;
    }
    res = 0;
    for(int i=0; i<n; i++){
        if(!(bit & (1 << i))){
            int t = md * pw[len[i]] + arr[i];
            res += f(bit | (1 << i), t % k);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i];
    }
    cin >> k;
    for(int i=0; i<n; i++){
        len[i] = s[i].size();
        int t = 0;
        for(auto c : s[i]){
            t *= 10; t %= k;
            t += c - '0'; t %= k;
        }
        arr[i] = t;
    }
    memset(dp, -1, sizeof dp);
    pw[0] = 1 % k;
    for(int i=1; i<55; i++) pw[i] = pw[i-1] * 10 % k;
    ll p = f(0, 0), q = 1;
    if(p == 0){
        cout << "0/1"; return 0;
    }
    for(int i=1; i<=n; i++) q *= i;
    ll g = gcd(p, q);
    p /= g; q /= g;
    cout << p << "/" << q;
}
