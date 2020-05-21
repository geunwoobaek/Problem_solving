#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> M,P;
int zero=0;
long long sum=0;
int main()
{   ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
    {   int temp;
        cin>>temp;
        if(temp>0) P.push_back(temp);
        else if(temp<0) M.push_back(temp);
        else zero++;
    }
    sort(P.begin(),P.end(),greater<int>());
    sort(M.begin(),M.end(),less<int>());
    if(P.size()>0)
    {for(int i=0;i<P.size()-1;i+=2)
    {   if(P[i]!=1&&P[i+1]!=1)
            sum+=(P[i]*P[i+1]);
        else
            sum+=(P[i]+P[i+1]);
    }
    }
    if(P.size()%2==1) sum+=P.back();
    if(M.size()>0)
    {for(int i=0;i<M.size()-1;i+=2)
    {
        sum+=(M[i]*M[i+1]);
    }
    }
    if(M.size()%2==1&&zero==0) sum+=M.back();
    cout<<sum;
    return 0;
}