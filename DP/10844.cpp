#include<bits/stdc++.h>
using namespace std;
#define mod 1000000000
int n,m,sum=0;
int DP[101][11];
int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i=1;i<10;i++) DP[1][i]=1;
    for(int i=1;i<100;i++){
        DP[i+1][0]=DP[i][1];
        for(int j=0;j<9;j++) DP[i+1][j]=(DP[i][j-1]+DP[i][j+1])%mod;
        DP[i+1][9]=DP[i][8];
    }
    
    for(int i=0;i<10;i++) sum=(sum+DP[n][i])%mod;
    cout<<sum;
    return 0;
}