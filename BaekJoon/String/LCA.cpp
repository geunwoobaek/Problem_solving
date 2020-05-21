#include<iostream>
#include<vector>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int Max=0;
int DP[41][41];
string result="";
string A,B;
int x=1,y=1;
int M=1e9;
int main()
{
cin>>A>>B;
A.insert(0,1,'-');B.insert(0,1,'-');
int most_length=max(A.size(),B.size());
for(int k=1;k<most_length;k++)
{   
for(int i=1;i<A.size()&&i<=k;i++)
{
    for(int j=1;j<B.size()&&j<=k;j++)
    {
     if(A[i]==B[j]) {
         DP[i][j]=DP[i-1][j-1]+1;
         }
     else DP[i][j]=DP[i-1][j]>DP[i][j-1]?DP[i-1][j]:DP[i][j-1];
    
     if(Max<DP[i][j]) {
         Max=DP[i][j];
         cout<<A[i];
        }
    }
}
}

cout<<"";
return 0;
}