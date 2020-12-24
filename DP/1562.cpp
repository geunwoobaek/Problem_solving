#include<bits/stdc++.h>
using namespace std;
#define mod 1000000000
int cache[100][1<<10][10]; //[해당길이부터 n길이까지],[현재체크된수],[마지막수]
int n,m,sum=0,full=(1<<10)-1;
int dfs(int length,int check,int last){
if(last==10||last==-1) return 0; 
if(check==full) sum+=1;
else if(length==n){
    if(check==full) return 1;
    else return 0;
}
int &result=cache[length][check][last];
if(result!=-1) return result;
else result=0;
result=dfs(length+1,check|1<<(last+1),last+1)%mod+dfs(length+1,check|1<<(last-1),last-1)%mod;
return result%=mod;

}
int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    memset(cache,-1,sizeof(cache));
    for(int i=1;i<10;i++){
        dfs(1,1<<i,i);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            sum+=cache[i][full][j];
        }
    }
    cout<<sum;
    return 0;
}