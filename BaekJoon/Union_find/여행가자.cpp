#include<iostream>
using namespace std;
#define Max 1001
#define FOR(i,S,E) for(int i=S;i<=E;i++)
int N,M;
int arr[Max][Max];
int parent[Max];
int find_parent(int a)
{
    if(parent[a]==a) return a;
    return parent[a]=find_parent(parent[a]);
}
void merge(int a,int b)
{
int temp1=find_parent(a);
int temp2=find_parent(b);
if(temp1==temp2) return;
if(temp1<temp2) parent[temp2]=temp1;
else parent[temp1]=temp2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    FOR(i,1,N)
    {   
        if(parent[i]==0) parent[i]=i;
        FOR(j,1,N)
        {
            cin>>arr[i][j];
            if(parent[j]==0) parent[j]=j;   
            if(arr[i][j]==1)
            {
                merge(i,j);
            }
        }
    }  
    int temp,P;
    cin>>temp;  
    P=find_parent(temp);
    FOR(i,1,M-1)
    {  
        cin>>temp;
        if(find_parent(temp)!=P) cout<<"NO",exit(0);
    }
    cout<<"YES";
    return 0;
}