#include<iostream>
using namespace std;
int N,K,T,S=0,sum=0,len=0,M=2e9;
int arr[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {   len++;
        cin>>arr[i];
        sum+=arr[i];
        if(sum>=K)
        {
            while(S<=i)
            {   
                if(sum-arr[S]>=K)
                {   sum-=arr[S];
                    len--;   
                    S++;  
                }   
                else break; 
            }
            M=M>len?len:M;
        }
    }
    if(M==2e9) cout<<0;
    else cout<<M;
    return 0;
}